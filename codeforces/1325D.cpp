#include <cstdint>
#include <iostream>

void solve() noexcept {
  std::uint64_t sum{};
  std::uint64_t xor_v{};
  std::cin >> xor_v >> sum;

  if (sum == xor_v) {
    if (sum == 0) {
      std::cout << "0";
      return;
    }
    std::cout << "1\n" << sum;
    return;
  }

  if (xor_v > sum or ((sum - xor_v) & 1ULL) == 1ULL) {
    std::cout << "-1";
    return;
  }

  auto diff_x = (sum - xor_v) / 2;

  if ((diff_x & xor_v) == 0ULL) {
    std::cout << "2\n" << xor_v + diff_x << " " << diff_x;
  } else {
    std::cout << "3\n" << xor_v << " " << diff_x << " " << diff_x;
  }
}