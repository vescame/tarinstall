#include "../../include/parser/parser.hpp"
#include <string>

const sptr<std::string>
parser::to_str(const char* str) {
  return to_sptr<std::string>(str);
}

