#include "registry.h"
#include <iostream>

namespace shelly {

bool Registry::isBuildinCommand(std::string name) {
  auto it = reg.find(name);
  return it != reg.end();
}

Registry &Registry::WithCommand(std::string name,
                                std::shared_ptr<buildin::Builtin> cmd) {

  auto ret = reg.insert({name, cmd});
  if (!ret.second) {
    std::cout << "Failed to insert " << name << " command" << std::endl;
  }
  return *this;
}

std::shared_ptr<buildin::Builtin> Registry::GetCommand(std::string name) {

  auto it = reg.find(name);
  if (it == reg.end()) {
    return nullptr;
  }
  return it->second;
}
} // namespace shelly
