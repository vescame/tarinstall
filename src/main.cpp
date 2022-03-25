#include <iostream>
#include "../include/parser/parser.hpp"
#include "../include/files/copy_file.hpp"
#include "../include/args/input_args.hpp"
#include "../include/logging/logger.hpp"

auto make_copy = [] (const char* a1, const char* a2) {
  files::copy_structure(to_sptr(std::string(a1)), to_sptr(std::string(a2)));
};

int
main(int argc, char** argv)
{
  if (argc < 3) logging::error("must have two args $src $dst", 1);
  auto args = args::handle(argv, argc);

  make_copy(args[0].c_str(), args[1].c_str());

  return 0;
}

