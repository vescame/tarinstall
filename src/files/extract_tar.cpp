#include "../../include/files/extract_tar.hpp"
#include "../../include/logging/logger.hpp"
#include <archive.h>

void
extract::begin(const std::string src, const std::string dst)
{
  struct archive* src_archive;
  struct archive* dst_archive;
  int r;
  size_t size;
  la_int64_t offset;
  const void *buff;

  src_archive = archive_read_new();
  archive_read_open_filename(src_archive, src.c_str(), 10240);
  dst_archive = archive_write_disk_new();
  archive_write_open_filename(dst_archive, dst.c_str());

  for (;;) {
    r = archive_read_data_block(src_archive, &buff, &size, &offset);
    if (r == ARCHIVE_EOF) return;

    if (r < ARCHIVE_OK) {
      std::string message = "failed to read tar file " + src + " with error: " +
        archive_error_string(src_archive);
      logging::error(message, 12);
    }

    r = archive_write_data_block(dst_archive, buff, size, offset);
    if (r < ARCHIVE_OK)
    {
      std::string message = "failed to write tar file to " + dst + " with error: " +
        archive_error_string(dst_archive);
      logging::error(message, 13);
    }
  }
}

