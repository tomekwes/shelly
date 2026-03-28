#pragma once

#include "prompt.h"
#include "util.h"
#include "execute.h"
#include <cstdlib>

namespace shelly {

struct shelly {

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

      util::print_container(cmd_args);

      decltype(cmd_args) args{cmd_args.begin()+1, cmd_args.end()};
      execue_command(cmd_args[0], args);

      // if (cmd_args[0] == "quit") {
      //   exit 0;
      // }
    }
  }
};

} // namespace shelly
