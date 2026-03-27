#pragma once

#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

namespace shelly {

void execue_command(std::string program_name) {

  pid_t pid{};
  pid_t wpid{};
  int status;
  std::vector<char*> c_args;
  c_args.push_back(nullptr);

  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(program_name.c_str(), c_args.data()) == -1) {
      std::cout << "something went wrong" << std::endl;
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
