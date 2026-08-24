#include <algorithm>
#include <cstdint>
#include <iostream>

void solve() noexcept {
  std::uint32_t friends{};
  std::uint32_t bottles{};
  std::uint32_t ml_per_bottle{};
  std::uint32_t limes{};
  std::uint32_t slices_per_lime{};
  std::uint32_t salt{};

  std::uint32_t ml_per_toast{};
  std::uint32_t salt_per_toast{};

  std::cin >> friends >> bottles >> ml_per_bottle >> limes >> slices_per_lime >>
      salt >> ml_per_toast >> salt_per_toast;

  std::uint32_t limit_one =
      ((bottles * ml_per_bottle) / (friends * ml_per_toast)) + 1;
  std::uint32_t limit_two = ((limes * slices_per_lime) / friends) + 1;
  std::uint32_t limit_three = (salt / (friends * salt_per_toast)) + 1;

  std::cout << std::min({limit_one, limit_two, limit_three}) - 1 << "\n";
}