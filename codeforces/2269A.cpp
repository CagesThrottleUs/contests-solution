#include <cstdint>
#include <iostream>

struct Inputs {
  std::uint16_t total_days;
  std::uint16_t withdrawal_days;
};

inline auto get_max_amt_in_card(const Inputs& input) -> std::uint32_t {
  std::uint32_t first = 1U << (input.total_days - input.withdrawal_days + 1U);
  std::uint32_t second = (input.withdrawal_days - 1U) << 1U;
  return first + second;
}

void solve() noexcept {
  std::uint16_t tests{};
  std::cin >> tests;

  while (tests > 0) {
    tests--;
    std::uint16_t total_days{};
    std::uint16_t withdrawal_days{};
    std::cin >> total_days >> withdrawal_days;

    std::cout << get_max_amt_in_card({
                     .total_days = total_days,
                     .withdrawal_days = withdrawal_days,
                 })
              << "\n";
  }
}