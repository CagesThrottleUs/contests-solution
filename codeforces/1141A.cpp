#include <bit>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <iostream>

[[nodiscard]] inline auto get_max_powers(std::uint32_t num)
    -> std::pair<std::uint32_t, std::uint32_t> {
  if (num == 0) {
    return {0, 0};
  }

  // Base 2 power: Bitwise lowest set bit
  auto power2 = static_cast<std::uint32_t>(std::countr_zero(num));

  // Base 3 power: Iterative reduction
  std::uint32_t power3 = 0;
  while (num % 3 == 0) {
    num /= 3;
    power3++;
  }

  return {power2, power3};
}

void solve() noexcept {
  std::uint32_t start{};
  std::uint32_t end{};

  std::cin >> start >> end;

  if (end % start != 0) {
    std::cout << "-1\n";
    return;
  }

  auto num = end / start;

  auto pows = get_max_powers(num);

  constexpr double THREE = 3.0;

  auto mul = static_cast<std::uint32_t>((1U << pows.first) *
                                        (std::pow(THREE, pows.second * 1.0)));

  if (num / mul != 1) {
    std::cout << "-1\n";
    return;
  }

  std::cout << pows.first + pows.second << "\n";
}