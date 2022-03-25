#include "../../include/files/copy.hpp"
#include <fstream>
#include <filesystem>

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
  std::filesystem::path path_from = std::string(from);
  std::filesystem::path path_to = to;
  std::filesystem::copy(path_from, path_to, std::filesystem::copy_options::recursive);
}

