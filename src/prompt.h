#pragma once

#include <string>
#include <vector>

namespace shelly {
struct prompt {

  int loop();

private:
  std::vector<std::string> readLine();
  void printCaret() const;

  std::vector<std::string> last_command_;
};
} // namespace shelly
