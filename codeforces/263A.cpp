#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <utility>

inline auto loop_mat() noexcept -> std::pair<std::uint16_t, std::uint16_t> {
  const std::uint16_t MAT_SIZE = 5;
  std::uint16_t pos_x{1};

  while (pos_x <= MAT_SIZE) {
    std::uint16_t pos_y{1};
    while (pos_y <= MAT_SIZE) {
      char _ch{};
      std::cin >> _ch;

      if (_ch == '1') {
        [[unlikely]] return std::make_pair(pos_x, pos_y);
      }
      pos_y++;
    }
    pos_x++;
  }
  return std::make_pair(0, 0);
}

void solve() noexcept {
  auto val = loop_mat();
  // std::cout << "[DEBUG] " << val.first << " " << val.second << '\n';
  const std::uint16_t CENTER_IDX = 3;
  std::cout << std::abs(val.first - CENTER_IDX) +
                   std::abs(val.second - CENTER_IDX)
            << '\n';
}