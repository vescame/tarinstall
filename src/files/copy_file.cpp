#include "../include/files/copy_file.hpp"
#include <fstream>
#include <filesystem>

void
files::copy(const char* from, const char* to)
{
  std::ifstream src(from, std::ios::binary);
  std::ofstream dst(to, std::ios::binary);

  dst << src.rdbuf();
}

void
files::copy_structure(const char *from, const char *to)
{
  std::filesystem::path p_from = from;
  std::filesystem::path p_to = to;
  std::filesystem::copy(p_from, p_to, std::filesystem::copy_options::recursive);
}

