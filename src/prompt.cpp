#include "prompt.h"
#include "util.h"
#include <bits/stdc++.h>
#include <ranges>
#include <string>

namespace shelly {

/// Read line from input stream
/// TODO:
/// support operator | ; && ||
/// fill last command to $?
std::vector<std::string> prompt::readLine() {

  std::string command_and_arguments{};
  std::getline(in.get(), command_and_arguments);
  auto tokens{util::WordExpansion{command_and_arguments}.getTokens()};
  last_command_ = tokens;
  return tokens;
}

/// Wrtie to output stream caret symbol
/// TODO:
/// Add user define caret symbols
/// with commands that could get username or git branch
void prompt::printCaret() const { out.get() << "> "; }

} // namespace shelly
