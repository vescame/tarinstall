#include "../../include/args/input_args.hpp"

const std::vector<std::string>
args::handle(char** argv, int argc) {
  std::vector<std::string> obtained;
  for (int i = 1; i < argc; ++i) {
    obtained.push_back(argv[i]);
  }
  return obtained;
}

