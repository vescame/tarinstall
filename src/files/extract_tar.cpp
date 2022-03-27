#include "../../include/files/extract_tar.hpp"
#include "../../include/logging/logger.hpp"

void
extract::begin(const std::string src, const std::string dst)
{
  struct archive* src_archive;
  struct archive* dst_archive;
  struct archive_entry* entry;
  int flags;
  int r;

  const char* filename = src.c_str();

  flags = ARCHIVE_EXTRACT_TIME;
  flags |= ARCHIVE_EXTRACT_PERM;
  flags |= ARCHIVE_EXTRACT_ACL;
  flags |= ARCHIVE_EXTRACT_FFLAGS;

  src_archive = archive_read_new();
  archive_read_support_format_all(src_archive);
  archive_read_support_filter_xz(src_archive);

  dst_archive = archive_write_disk_new();
  archive_write_disk_set_options(dst_archive, flags);
  archive_write_disk_set_standard_lookup(dst_archive);

  if (archive_read_open_filename(src_archive, filename, 1024))
  {
    const std::string message = "failed to read source archive " + src +
      " with error: " + archive_error_string(src_archive);
    logging::error(message, 11);
  }

  for (;;)
  {
    r = archive_read_next_header(src_archive, &entry);
    if (r == ARCHIVE_EOF) break;

    if (r < ARCHIVE_OK)
    {
      const std::string message = "failed to read tar file " + src + " with error: " +
        archive_error_string(src_archive);
      logging::error(message, 12);
    }

    if (r < ARCHIVE_WARN)
    {
      logging::error(archive_error_string(src_archive), 13);
    }

    // TODO: check pathname before assign
    std::string new_name = dst + "/" + archive_entry_pathname(entry);
    archive_entry_set_pathname(entry, new_name.c_str());
    logging::warn(archive_entry_pathname(entry));

    r = archive_write_header(dst_archive, entry);
    if (r < ARCHIVE_OK)
    {
      const std::string message = "failed to write to target path " + dst + " with error: " +
        archive_error_string(dst_archive);
      logging::error(message, 13);
    }
    else if (archive_entry_size(entry) > 0)
    {
      r = extract::copy_data(src_archive, dst_archive);
      if (r < ARCHIVE_OK)
      {
        const std::string message = "failed to copy data from tar file " + src +
          " to tar file " + dst + " with error: " + archive_error_string(src_archive);
        logging::error(message, 14);
      }

      if (r < ARCHIVE_WARN)
      {
        logging::error(archive_error_string(src_archive), 15);
      }
    }

    r = archive_write_finish_entry(dst_archive);

    if (r < ARCHIVE_OK) logging::warn(archive_error_string(dst_archive));

    if (r < ARCHIVE_WARN) logging::error(archive_error_string(src_archive), 16);
  }

  archive_read_close(src_archive);
  archive_read_free(src_archive);
  archive_write_close(dst_archive);
  archive_write_free(dst_archive);
}

int
extract::copy_data(struct archive* src_archive, struct archive* dst_archive)
{
  int r;
  const void* buffer;
  size_t size;
  la_int64_t offset;

  for (;;)
  {
    r = archive_read_data_block(src_archive, &buffer, &size, &offset);
    if (r == ARCHIVE_EOF) return (ARCHIVE_OK);

    if (r < ARCHIVE_OK) return (r);

    r = archive_write_data_block(dst_archive, buffer, size, offset);
    if (r < ARCHIVE_OK)
    {
      logging::warn(archive_error_string(src_archive));
      return (r);
    }
  }
}

