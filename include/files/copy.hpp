#include <string>

#ifndef FILES_COPY
#define FILES_COPY
namespace files {
  void copy(const std::string from, const std::string to);
  void copy_structure(const std::string from, const std::string to);
}
#endif

