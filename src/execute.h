#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

namespace shelly {


inline void execue_command(std::string program_name, std::vector<std::string> program_args) {

  pid_t pid{};
  pid_t wpid{};
  int status;
  std::vector<char *> c_args;
  std::for_each(program_args.begin(), program_args.end(), [&c_args]( std::string& elem){c_args.push_back(elem.data());});
  c_args.push_back(nullptr); //null terminate string passed to ececvp

  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(program_name.c_str(), c_args.data()) == -1) {
      std::cout << "Something went wrong, probably unknown command" << std::endl;
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    std::cout << "Error forking" << std::endl;
  } else {
    // Parent process
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
}

} // namespace shelly
