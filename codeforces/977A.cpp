#include <cstdint>
#include <iostream>

void solve() noexcept {
  std::uint32_t num{};
  std::uint16_t operations{};
  std::cin >> num >> operations;

  constexpr std::uint32_t BASE = 10;

  while (operations > 0) {
    if (num % BASE == 0) {
      num = num / BASE;
    } else {
      num--;
    }
    operations--;
  }

  std::cout << num << "\n";
}