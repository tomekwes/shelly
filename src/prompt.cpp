#include "prompt.h"
#include "execute.h"
#include "util.h"
#include <bits/stdc++.h>
#include <ranges>
#include <string>

namespace shelly {

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

void prompt::printCaret() const { out.get() << "> "; }


} // namespace shelly
