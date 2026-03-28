#pragma once

#include "execute.h"
#include "prompt.h"
#include "util.h"
#include <cstdlib>

namespace shelly {

/// TODO:
/// handle singals like CTRL+C
struct shelly {

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
      prompt prt;
      prt.printCaret();
      auto cmd_args = prt.readLine();
      if (cmd_args.size() == 0) {
        continue;
      }

      execue_command(cmd_args[0], cmd_args);

      // if (cmd_args[0] == "quit") {
      //   exit 0;
      // }
    }
  }
};

} // namespace shelly
