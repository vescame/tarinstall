#include "../../include/parser/parser.hpp"
#include <string>

const str_ptr
parser::to_str(const char* str) {
  return std::make_shared<std::string>(str);
}

