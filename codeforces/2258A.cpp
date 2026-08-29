#include <cstddef>
#include <cstdint>
#include <iostream>
#include <numeric>

void solve_test() noexcept {
  std::size_t size{};
  std::cin >> size;

  std::uint32_t first{};
  std::uint32_t last{};

  for (std::size_t i{0}; i < size; i++) {
    std::uint32_t num{};
    std::cin >> num;
    if (i == 0) {
      first = num;
    }
    if (i == (size - 1)) {
      last = num;
    }
  }

  std::cout << std::gcd(first, last) << "\n";
}

void solve() noexcept {
  std::uint16_t tests{};
  std::cin >> tests;

  while (tests > 0) {
    tests--;
    solve_test();
  }
}