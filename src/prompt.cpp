#include "prompt.h"
#include "util.h"
#include <bits/stdc++.h>
#include <ranges>
#include <string>

namespace shelly {

std::vector<std::string> prompt::readLine() {

  std::string command_and_arguments{};
  std::getline(std::cin, command_and_arguments);
  auto tokens = command_and_arguments | std::views::split(' ') |
                std::ranges::to<std::vector<std::string>>();
  last_command_ = tokens;
  return tokens;
}

void prompt::printCaret() const { std::cout << "> "; }

int prompt::loop() {

  while (true) {
    printCaret();
    auto cmd_args = readLine();

    util::print_container(cmd_args);

    if(cmd_args[0] == "quit"){
        return 0;
    }
  }
}

} // namespace shelly
