#include "../../include/files/copy.hpp"
#include "../../include/logging/logger.hpp"
#include <fstream>

void
files::copy(const std::string from, const std::string to)
{
  std::ifstream src(from, std::ios::binary);
  std::ofstream dst(to, std::ios::binary);

  dst << src.rdbuf();
}

void
files::copy_structure(const std::string from, const std::string to)
{
  efs::path path_from = from;
  efs::path path_to = to;
  efs::copy(path_from, path_to, efs::copy_options::recursive);
}

efs::path
files::normalize_path(const std::string path) {
  return efs::canonical(efs::path(path));
}

void
files::exists_or_die(const efs::path& path) noexcept
{
  if (!efs::exists(path))
  {
    std::string message = "path " + std::string(path.c_str()) + " doesn't exists";
    logging::error(message, 30);
  }
}

