#pragma once

#include "builtin.h"
#include <list>
#include <ranges>
#include <unistd.h>

namespace shelly::builtin {

// TO DO: save to file
struct History : public Builtin {

  // This is not the best idea
  // but it will do for now
  std::list<std::string> commands;

  void record(const std::vector<std::string> &cmd) {
    commands.push_back(cmd | std::views::join_with(' ') |
                       std::ranges::to<std::string>());
  }

  virtual std::optional<std::string> execute(const std::vector<std::string> &) {
    return commands | std::views::join_with('\n') |
           std::ranges::to<std::string>();
  }
};

} // namespace shelly::builtin
