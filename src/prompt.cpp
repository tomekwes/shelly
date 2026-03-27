#include "prompt.h"
#include "util.h"
#include <bits/stdc++.h>
#include <ranges>
#include <string>

namespace shelly {

std::vector<std::string> prompt::readLine() {

  std::string command_and_arguments{};
  std::getline(std::cin, command_and_arguments);
  auto tokens = command_and_arguments
                 | std::views::split(' ')
                 | std::ranges::to<std::vector<std::string>>();
  last_command_ = tokens;
  return tokens;
}

void printCaret(){
    std::cout << "> ";
}

void prompt::loop() {

  while (true) {
    auto cmd_args = readLine();

    util::print_container(cmd_args);
  }
}

} // namespace shelly
