#pragma once

#include <optional>
#include <string>
#include <vector>

namespace shelly::builtin {

struct Builtin {
  virtual ~Builtin() = default;
  // Idea: maybe std::expected would be better here
  virtual std::optional<std::string>
  execute(const std::vector<std::string> &args) = 0;
};

} // namespace shelly::builtin
