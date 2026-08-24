#include <cstddef>
#include <cstdint>
#include <iostream>
#include <limits>
#include <utility>

inline auto get_idx(std::uint16_t num_soldiers)
    -> std::pair<std::uint16_t, std::uint16_t> {
  std::uint16_t tallest{0};
  std::size_t tallest_idx{0};

  std::uint16_t shortest{std::numeric_limits<std::uint16_t>::max()};
  std::size_t shortest_idx{0};

  std::size_t curr_idx{0};

  while (num_soldiers > 0) {
    num_soldiers--;
    std::uint16_t height{};
    std::cin >> height;

    if (tallest < height) {
      tallest = height;
      tallest_idx = curr_idx;
    }
    if (shortest >= height) {
      shortest = height;
      shortest_idx = curr_idx;
    }
    curr_idx++;
  }

  return std::make_pair(shortest_idx, tallest_idx);
}

void solve() noexcept {
  std::uint16_t num_soldiers{};
  std::cin >> num_soldiers;

  const std::size_t last = num_soldiers - 1;

  auto [shortest_idx, tallest_idx] = get_idx(num_soldiers);

  bool will_cross{shortest_idx < tallest_idx};

  auto res = (tallest_idx - 0) + (last - shortest_idx);

  if (will_cross) {
    std::cout << res - 1 << '\n';
  } else {
    std::cout << res << '\n';
  }
}