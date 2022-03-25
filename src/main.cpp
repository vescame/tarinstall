#include <iostream>
#include "../include/files/copy.hpp"
#include "../include/args/input_args.hpp"
#include "../include/logging/logger.hpp"
#include "../include/pointers/safe_ptrs.hpp"

int
main(int argc, char** argv)
{
  if (argc < 3) logging::error("must have two args $src $dst", 1);
  auto args = args::handle(argv, argc);

  auto from = args[0].c_str();
  auto to = args[1].c_str();

  files::copy_structure(from, to);

  return 0;
}

