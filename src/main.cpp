#include <iostream>
#include "../include/parser/parser.hpp"
#include "../include/files/copy_file.hpp"
#include "../include/args/input_args.hpp"
#include "../include/logging/logger.hpp"

void
copyfiles(const str_ptr from, const str_ptr to) { files::copy_structure(from, to); }


auto make_copy = [] (const char* a1, const char* a2) {
  auto to_str_ptr = [] (const char* str) { return std::make_shared<std::string>(str); };
  copyfiles(to_str_ptr(a1), to_str_ptr(a2));
};

int
main(int argc, char** argv)
{
  if (argc < 3) logging::error("must have two args $src $dst", 1);
  auto args = args::handle(argv, argc);

  make_copy(args[0].c_str(), args[1].c_str());

  return 0;
}

