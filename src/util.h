#pragma once

#include <iostream>
#include <ranges>
#include <string>
#include <vector>

namespace shelly::util {

template <std::ranges::range R> auto to_vector(R &&r) {
  auto r_common = r | std::views::common;
  return std::vector(r_common.begin(), r_common.end());
}

template <typename Container> void print_container(const Container &c) {
  std::cout << "[";
  auto it = c.cbegin();
  for (typename Container::size_type i{0}; i < c.size() - 1; i++) {
    std::cout << *it << ",";
    it++;
  }
  std::cout << *it << "]" << std::endl;
}

} // namespace shelly::util
