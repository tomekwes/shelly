#pragma once

#include "builtin.h"
#include <unistd.h>

namespace shelly::builtin {

struct Exit : public Builtin {

  virtual std::optional<std::string> execute(const std::vector<std::string> &) {
    exit(0);
  }
};

} // namespace shelly::builtin
