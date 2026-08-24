#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

void handle_test_case() noexcept {
  std::uint16_t number{};
  std::cin >> number;

  const std::uint16_t BASE = 10;

  std::vector<std::pair<std::uint16_t, std::uint16_t>> rems;

  std::uint16_t exponent{0};

  while (number > 0) {
    auto rem = number % BASE;
    number /= BASE;
    if (rem != 0) {
      rems.emplace_back(rem, exponent);
    }
    exponent++;
  }

  std::cout << rems.size() << '\n';
  for (const auto& rem: rems) {
    std::cout << rem.first << std::string(rem.second, '0') << ' ';
  }
  std::cout << '\n';
}

void solve() noexcept {
  std::uint16_t num_tests{};
  std::cin >> num_tests;

  while (num_tests > 0) {
    num_tests--;
    handle_test_case();
  }
}