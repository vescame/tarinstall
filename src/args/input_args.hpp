#include <string>
#include <vector>

#ifndef ARGS_HANDLER_HPP
#define ARGS_HANDLER_HPP
namespace args {
  const std::vector<std::string> handle(char** argv, int argc);
}
#endif
