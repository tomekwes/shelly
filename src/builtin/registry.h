#pragma once

#include "builtin.h"
#include <memory>
#include <unordered_map>

namespace shelly {
struct Registry {

  std::unordered_map<std::string, std::shared_ptr<builtin::Builtin>> reg;

  bool isBuiltinCommand(std::string name);
  Registry &WithCommand(std::string name,
                        std::shared_ptr<builtin::Builtin> cmd);
  std::shared_ptr<builtin::Builtin> GetCommand(std::string name);
};

} // namespace shelly
