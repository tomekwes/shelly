#pragma once

#include <optional>
#include <string>
#include <vector>

namespace shelly::buildin {

struct Builtin {
  virtual ~Builtin() = default;
  virtual std::optional<std::string>
  execute(const std::vector<std::string> &args) = 0;
};

} // namespace shelly::buildin
