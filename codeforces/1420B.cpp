#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>

namespace constants {
  constexpr std::size_t TOTAL_BITS = 32;
};

inline void test() noexcept {
  std::size_t arr_sz{};
  std::cin >> arr_sz;

  std::size_t total_pairs{0};

  std::array<std::size_t, constants::TOTAL_BITS> bit_map{{0}};

  for (std::size_t i{0}; i < arr_sz; i++) {
    std::uint32_t num{};
    std::cin >> num;

    std::size_t pos{0};
    while (num > 0) {
      num >>=1;
      if (num == 0) {
        total_pairs += bit_map.at(pos);
        bit_map.at(pos)++;
      }
      pos++;
    }
  }

  std::cout << total_pairs << "\n";
}

void solve() noexcept {
  std::uint16_t tests{};
  std::cin >> tests;

  while (tests > 0) {
    tests--;
    test();
  }
}