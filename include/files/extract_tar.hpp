#include <archive.h>
#include <archive_entry.h>
#include <string>

#ifndef EXTRACT_TAR_HPP
#define EXTRACT_TAR_HPP
namespace extract {
  void begin(const std::string src, const std::string dst);
  int copy_data(struct archive* ar, struct archive* aw);
};
#endif
