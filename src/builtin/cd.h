#pragma once

#include "builtin.h"
#include <iostream>
#include <unistd.h>

namespace shelly::buildin {

struct Cd : public Builtin {

  virtual std::optional<std::string>
  execute(const std::vector<std::string> &args) {

    if (args.size() < 2) {
      // TODO: here it should go to home dir
      // need to have env variables first
      std::cout << "Too few args";
    } else {
      if (chdir(args[1].c_str()) != 0) {
        std::cout << "chdir failed";
      }
    }
    return std::nullopt;
  }
};

} // namespace shelly::buildin
