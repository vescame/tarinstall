#include "../mem/ptrs.hpp"

#ifndef FILES_COPY
#define FILES_COPY
namespace files {
  void copy(const sptr<std::string> from, const sptr<std::string> to);
  void copy_structure(const sptr<std::string> from, const sptr<std::string> to);
}
#endif

