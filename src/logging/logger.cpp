#include "../include/logging/logger.hpp"
#include <iostream>

void
logging::info(const std::string message)
{
  std::cout << "INFO - " << message << std::endl;
}
void
logging::warn(const std::string message)
{
  std::cout << "WARN - " << message << std::endl;
}

void
logging::error(const std::string message, const int error_code)
{
  std::cout << "ERROR [" << error_code << "] - " << message << std::endl;
  exit(error_code);
}

