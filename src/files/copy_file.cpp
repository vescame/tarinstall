#include "../../include/files/copy_file.hpp"
#include <fstream>
#include <filesystem>

void
files::copy(const str_ptr from, const str_ptr to)
{
  std::ifstream src(from->c_str(), std::ios::binary);
  std::ofstream dst(to->c_str(), std::ios::binary);

  dst << src.rdbuf();
}

void
files::copy_structure(const str_ptr from, const str_ptr to)
{
  std::filesystem::path path_from = std::string(from->c_str());
  std::filesystem::path path_to = to->c_str();
  std::filesystem::copy(path_from, path_to, std::filesystem::copy_options::recursive);
}

