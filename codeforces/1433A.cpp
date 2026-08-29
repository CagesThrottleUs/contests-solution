#include <cstdint>
#include <iostream>

void solve_test() noexcept {
  std::uint16_t num{};
  std::cin >> num;

  constexpr std::uint16_t BASE = 10;

  auto last_digit = num % BASE;
  std::uint16_t total_digits{0};

  while (num > 0) {
    total_digits++;
    num /= BASE;
  }

  auto ans =
      (BASE * (last_digit - 1)) + ((total_digits * (total_digits + 1)) / 2);

  std::cout << ans << "\n";
}

void solve() noexcept {
  std::uint16_t tests{};
  std::cin >> tests;

  while (tests > 0) {
    tests--;
    solve_test();
  }
}