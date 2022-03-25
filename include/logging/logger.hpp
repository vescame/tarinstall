#include <string>

#ifndef LOGGER_HPP
#define LOGGER_HPP
namespace logging {
  void info(const std::string message);
  void warn(const std::string message);
  void error(const std::string message, const int error_code);
}
#endif
