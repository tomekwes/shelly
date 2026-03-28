#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

namespace shelly {

/// Execute single program and pass arguments to it
/// TODO:
/// Rework so that it uses parameter pack - maybe it would be better
inline void execue_command(std::string program_name,
                           std::vector<std::string> program_args) {

  pid_t pid{};
  pid_t wpid{};
  int status;
  std::array<int, 2> pipefd;
  std::vector<char *> c_args;
  std::for_each(
      program_args.begin(), program_args.end(),
      [&c_args](std::string &elem) { c_args.push_back(elem.data()); });
  c_args.push_back(nullptr); // null terminate string passed to ececvp

  if (pipe(pipefd.data()) == -1) {
    std::cout << "Pipe failed to create" << std::endl;
  }
  pid = fork();
  if (pid == 0) {
    // Child process
    close(pipefd[0]);               // Close unused read end
    dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to pipe write end
    close(pipefd[1]);               // Close original write end
    if (execvp(program_name.c_str(), c_args.data()) == -1) {
      std::cout << "Something went wrong, probably unknown command"
                << std::endl;
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    std::cout << "Error forking" << std::endl;
  } else {
    // Parent process
    close(pipefd[1]); // Close unused write end
    char buffer[4096];
    std::string captured_output;
    ssize_t bytes_read;
    // Read from pipe until child closes it (finishes)
    while ((bytes_read = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
      captured_output.append(buffer, bytes_read);
    }

    close(pipefd[0]); // Close read end
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    std::cout << "Captured: " << captured_output << std::endl;
  }
}

} // namespace shelly
