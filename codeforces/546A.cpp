#include <algorithm>
#include <cstdint>
#include <iostream>

void solve() noexcept {
  std::int32_t start_amt{};
  std::int32_t budget{};
  std::int32_t total_banana{};

  std::cin >> start_amt >> budget >> total_banana;

  auto ans = std::max(
      (((total_banana * (total_banana + 1)) / 2) * start_amt) - budget, 0);

  std::cout << ans << "\n";
}