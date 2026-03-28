#pragma once

#include "builtin.h"
#include <unistd.h>

namespace shelly::buildin {

struct Exit : public Builtin {

  virtual std::optional<std::string> execute(const std::vector<std::string> &) {
    exit(0);
  }
};

} // namespace shelly::buildin
