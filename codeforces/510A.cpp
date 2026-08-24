#include <cstdint>
#include <iostream>

void solve() noexcept {
  std::uint16_t num_rows{};
  std::uint16_t num_cols{};
  std::cin >> num_rows >> num_cols;

  for (std::uint16_t row{1}; row <= num_rows; row++) {
    auto is_even = (row % 2 == 0);
    auto is_first = is_even and (row % 4 == 0);

    for (std::uint16_t col{1}; col <= num_cols; col++) {
      if (!is_even) {
        [[likely]] std::cout << '#';
      } else {
        if ((col == 1 and is_first) or (col == num_cols and !is_first)) {
          std::cout << '#';
        } else {
          [[likely]] std::cout << '.';
        }
      }
    }
    std::cout << '\n';
  }
}