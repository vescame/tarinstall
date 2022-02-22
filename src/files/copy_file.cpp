#include "copy_file.hpp"
#include <fstream>

void
files::copy(const char* from, const char* to)
{
  std::ifstream src(from, std::ios::binary);
  std::ofstream dst(to, std::ios::binary);

  dst << src.rdbuf();
}

