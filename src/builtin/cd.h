#pragma once

#include "builtin.h"
#include <cerrno>
#include <cstddef>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <unistd.h>

namespace shelly::buildin {

struct Cd : public Builtin {

  void save_path_andchange_dir(const char *path) {
    auto tmp_path = std::filesystem::current_path();
    if (chdir(path) != 0) {
      std::cout << "chdir failed errno " << errno << " path " << path
                << std::endl;
      return;
    }
    previous_path = tmp_path;
  }

  virtual std::optional<std::string>
  execute(const std::vector<std::string> &args) {
    if (args.empty()) {
      std::cout << "Argumnetn list should not be empty" << std::endl;
      return std::nullopt;
    }

    // Just the programs name was passed -> go to home directory
    if (args.size() == 1) {

      if (char *home_path = std::getenv("HOME"); home_path != NULL) {
        save_path_andchange_dir(home_path);
        return std::nullopt;
      }
      std::cout << "$HOME not found" << std::endl;
      return std::nullopt;
    }

    // More than 1 arg

    // The 'go back' mechanic
    if (args[1] == "-") {
      if (previous_path.has_value()) {
        save_path_andchange_dir(previous_path->c_str());
        return std::nullopt;
      } else {
        std::cout << "No previous path" << std::endl;
        return std::nullopt;
      }
    }

    save_path_andchange_dir(args[1].c_str());
    return std::nullopt;
  }

  std::optional<std::filesystem::path> previous_path{std::nullopt};
};

} // namespace shelly::buildin
