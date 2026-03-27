#pragma once

#include <string>
#include <vector>

namespace shelly{
struct prompt{

    void loop();

    private:
    std::vector<std::string> readLine();
    void printCaret();

    std::vector<std::string> last_command_;

};
}
