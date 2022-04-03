#include <string>
#include <experimental/filesystem>

#ifndef FILES_COPY
#define FILES_COPY
namespace efs = std::experimental::filesystem;
namespace files {
  void copy(const std::string, const std::string);
  void copy_structure(const std::string, const std::string);
  efs::path normalize_path(const std::string);
  void exists_or_die(const efs::path&) noexcept;
}
#endif

