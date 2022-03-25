#include "../../include/files/copy.hpp"
#include <experimental/filesystem>
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
  namespace efs = std::experimental::filesystem;
  efs::path path_from = from;
  efs::path path_to = to;
  efs::copy(path_from, path_to, efs::copy_options::recursive);
}

