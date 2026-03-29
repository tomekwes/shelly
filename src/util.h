#pragma once

#include <iostream>
#include <ranges>
#include <vector>
#include <wordexp.h>

namespace shelly::util {

template <std::ranges::range R> auto to_vector(R &&r) {
  auto r_common = r | std::views::common;
  return std::vector(r_common.begin(), r_common.end());
}

template <typename Container> void print_container(const Container &c) {
  std::cout << "[";
  if (c.size() != 0) {
    auto it = c.cbegin();
    for (typename Container::size_type i{0}; i < c.size() - 1; i++) {
      std::cout << *it << ",";
      it++;
    }
    std::cout << *it;
  }
  std::cout << "]" << std::endl;
}

// Wrapper for wordexp_t
// This handles cased of quotes, globing, variables etc...
struct WordExpansion {

  WordExpansion(std::string input) {
    wordexp(input.c_str(), &data_, WRDE_NOCMD);
  }

  WordExpansion(const WordExpansion &) = delete;
  WordExpansion &operator=(const WordExpansion &) = delete;

  ~WordExpansion() { wordfree(&data_); }

  std::vector<std::string> getTokens() {
    return std::span<char *>{data_.we_wordv, data_.we_wordc} |
           std::ranges::to<std::vector<std::string>>();
  }

  wordexp_t data_{};
};

} // namespace shelly::util
