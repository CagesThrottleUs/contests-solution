#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>

namespace constants {

constexpr std::size_t NUM_DAYS = 7;

}  // namespace constants

void solve() noexcept {
  std::uint16_t pages{};
  std::cin >> pages;

  std::array<std::uint16_t, constants::NUM_DAYS> read_qty{};

  for (std::size_t i{0}; i < constants::NUM_DAYS; i++) {
    std::uint16_t val{};
    std::cin >> val;

    read_qty.at(i) = val;
  }

  std::size_t day_of_week{0};

  while (pages > 0) {
    if (pages <= read_qty.at(day_of_week)) {
      std::cout << day_of_week + 1 << "\n";
      break;
    }

    pages -= read_qty.at(day_of_week);
    day_of_week++;
    day_of_week %= constants::NUM_DAYS;
  }
}