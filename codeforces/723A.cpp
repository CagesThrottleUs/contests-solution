#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>

namespace constants {
const std::uint16_t TOTAL_INPUT = 3;
};  // namespace constants

auto get_input() noexcept -> std::array<std::uint16_t, constants::TOTAL_INPUT> {
  std::uint16_t first{};
  std::uint16_t second{};
  std::uint16_t third{};

  std::cin >> first >> second >> third;

  return std::array<std::uint16_t, constants::TOTAL_INPUT>(
      {first, second, third});
}

void solve() noexcept {
  auto arr = get_input();
  std::ranges::sort(arr);

  std::cout << arr.back() - arr.front() << '\n';
}