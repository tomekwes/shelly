# Shelly - the shell no one needs but I made it anyway

A shell for Linux build with C++23

## Build and run
```bash
# Clone the repository
git clone https://github.com/tomekwes/shelly.git shelly
cd shelly

# Configure and Build
cmake -S . -B build
cmake --build build

# Run the shell
./build/bin/shelly
```


## Running tests
```bash
./build/bin/unit_tests
# OR using ctest
cd build && ctest
```
