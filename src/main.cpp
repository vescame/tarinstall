#include <iostream>
#include "files/copy_file.hpp"
#include "args/input_args.hpp"
#include "logging/logger.hpp"

void
copyfiles(const char* from, const char* to)
{
  files::copy(from, to);
}

int
main(int argc, char** argv)
{
  if (argc < 2) logging::error("must have two args $src $dst", 1);
  auto args = args::handle(argv, argc);
  copyfiles(args.at(0).c_str(), args.at(1).c_str());

  return 0;
}

