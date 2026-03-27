#pragma once

#include <functional>
#include <iostream>
#include <string>
#include <vector>

namespace shelly {
struct prompt {

  int loop();
  void setStdIn(std::istream &s) { in = s; }
  void setStdOut(std::ostream &s) { out = s; }
  std::vector<std::string> readLine();
  void printCaret() const;

  std::vector<std::string> last_command_;

  private:
  std::reference_wrapper<std::istream> in{std::cin};
  std::reference_wrapper<std::ostream> out{std::cout};
};
} // namespace shelly
