#include <iostream>
#include "include/files/copy_file.hpp"
#include "include/args/input_args.hpp"
#include "include/logging/logger.hpp"

int
main(int argc, char** argv)
{
  if (argc < 3) logging::error("must have two args $src $dst", 1);
  std::vector<std::string> args = args::handle(argv, argc);

  std::string from = args[0].c_str();
  std::string to = args[1].c_str();

  files::copy_structure(from, to);

  return 0;
}
