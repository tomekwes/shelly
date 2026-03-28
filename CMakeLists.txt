cmake_minimum_required(VERSION 3.25) # Required for better C++23 support

project(shelly
    VERSION 1.0
    LANGUAGES CXX
)

# Force C++23 standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

# --- Fetch GoogleTest ---
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
  GIT_TAG        v1.14.0
)
# For Windows compatibility: prevents GTest from overriding your compiler settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Keep the binary output organized
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add your source files
add_executable(shelly
    src/main.cpp
    src/util.h
    src/prompt.cpp
    src/prompt.h
    src/execute.h
    src/shelly.h
    src/builtin/builtin.h
    src/builtin/cd.h
    src/builtin/exit.h
    src/builtin/registry.h
    src/builtin/registry.cpp
    src/builtin/all_commands.h
)

# Optional: Enable common warnings to keep your code sharp
target_compile_options(shelly PRIVATE -Wall -Wextra -Wpedantic)

# We create a separate binary just for tests
add_executable(unit_tests
    test/prompt_test.cpp
    src/prompt.h
    src/prompt.cpp  # Link the files you want to test
)
target_include_directories(unit_tests PRIVATE include)

# Link GTest
target_link_libraries(unit_tests
    PRIVATE
        GTest::gtest_main  # automatically provides a main() for tests
        GTest::gmock
)

# Enable "ctest" command
include(CTest)
add_test(NAME AllTests COMMAND unit_tests)
