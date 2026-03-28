#include "prompt.h"
#include <bits/stdc++.h>
#include <ranges>
#include <string>

namespace shelly {

/// Read line from input stream
/// TODO:
/// support operator | ; && ||
std::vector<std::string> prompt::readLine() {

  std::string command_and_arguments{};
  std::getline(in.get(), command_and_arguments);
  auto tokens =
      command_and_arguments | std::views::split(' ') |
      std::views::filter([](auto elem) { return !std::ranges::empty(elem); }) |
      std::ranges::to<std::vector<std::string>>();
  last_command_ = tokens;
  return tokens;
}

/// Wrtie to output stream caret symbol
/// TODO:
/// Add user define caret symbols
/// with commands that could get username or git branch
void prompt::printCaret() const { out.get() << "> "; }

} // namespace shelly
