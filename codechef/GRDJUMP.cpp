#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>

inline void solve_test() noexcept {
  std::uint32_t target_x{};
  std::uint32_t target_y{};
  std::uint32_t cost_r{};
  std::uint32_t cost_u{};
  std::uint32_t cost_d{};

  std::cin >> target_x >> target_y >> cost_r >> cost_u >> cost_d;

  auto lambda = [&](std::uint32_t loop_size) -> std::uint32_t {
    auto p_coeff = ((target_x - loop_size) / 2) + ((target_x - loop_size) % 2);
    auto q_coeff = ((target_y - loop_size) / 2) + ((target_y - loop_size) % 2);
    return (loop_size * cost_d) + (p_coeff * cost_r) + (q_coeff * cost_u);  //
  };

  std::uint32_t ans{std::numeric_limits<std::uint32_t>::max()};

  auto loop_lim = std::min(target_x, target_y);

  for (std::uint32_t loop_size = 0; loop_size <= loop_lim; loop_size++) {
    ans = std::min(ans, lambda(loop_size));
  }

  std::cout << ans << '\n';
}

void solve() noexcept {
  std::uint16_t tests{};
  std::cin >> tests;

  while (tests > 0) {
    tests--;
    solve_test();
  }
}