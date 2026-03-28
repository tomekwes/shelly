#pragma once

#include "builtin/all_commands.h"
#include "builtin/exit.h"
#include "builtin/registry.h"
#include "execute.h"
#include "prompt.h"

namespace shelly {

/// TODO:
/// handle singals like CTRL+C
struct shelly {

  shelly() {
    builtin_registry.WithCommand("cd", std::make_shared<buildin::Cd>())
        .WithCommand("exit", std::make_shared<buildin::Exit>());
  }

  /// Arguments passed to shelly
  /// TODO:
  /// config file path
  /// help
  /// version
  void parseArguments() {}

  int run() {
    parseArguments();
    loop();
    return 0;
  }

  void loop() {

    while (true) {

      // Collect user input
      prompt prt;
      prt.printCaret();
      auto cmd_args = prt.readLine();
      if (cmd_args.size() == 0) {
        continue;
      }

      // Check if its a built in command
      if (builtin_registry.isBuildinCommand(cmd_args[0])) {
        auto cmd = builtin_registry.GetCommand(cmd_args[0]);
        cmd->execute(cmd_args);
        continue;
      }

      // Try to execute program
      execue_command(cmd_args[0], cmd_args);
    }
  }

  Registry builtin_registry;
};

} // namespace shelly
