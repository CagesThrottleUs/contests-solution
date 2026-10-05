#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <unordered_map>

namespace constants {
constexpr std::size_t TOTAL_GROUPS = 9;
constexpr std::size_t CHAIN_2_SIZE = 8;
constexpr std::uint16_t BASE = 10;
}  // namespace constants

inline auto get_next(std::uint64_t current) -> std::uint64_t {
  std::uint64_t next{0};
  while (current > 0) {
    auto digit = current % constants::BASE;
    next += (digit * digit);
    current /= constants::BASE;
  }
  return next;
}

inline void test() noexcept {
  std::uint16_t n_lighthouses{};
  std::cin >> n_lighthouses;

  std::array<std::size_t, constants::TOTAL_GROUPS> grp_sizes{};
  grp_sizes.fill(0);

  static const std::unordered_map<std::uint64_t, std::size_t> num_map_to_grp = {
      {1, 0},  {4, 1},   {16, 2}, {37, 3}, {58, 4},
      {89, 5}, {145, 6}, {42, 7}, {20, 8},
  };
  static const std::unordered_map<std::uint64_t, std::size_t> num_to_offset = {
      {4, 0}, {16, 1}, {37, 2}, {58, 3}, {89, 4}, {145, 5}, {42, 6}, {20, 7},
  };

  static const std::array<std::uint64_t, constants::CHAIN_2_SIZE> chain_2{
      {4, 16, 37, 58, 89, 145, 42, 20},
  };

  auto handle_grps = [&](std::uint64_t& curr, std::uint64_t& day) -> void {
    if (curr != 1) {
      auto curr_offset = num_to_offset.at(curr);
      for (std::size_t start_offset{0}; start_offset < num_to_offset.size();
           start_offset++) {
        if ((start_offset + day) % num_to_offset.size() == curr_offset) {
          curr = chain_2.at(start_offset);
          break;
        }
      }
    }
    grp_sizes.at(num_map_to_grp.at(curr))++;
  };

  for (std::size_t i{0}; i < n_lighthouses; i++) {
    std::uint64_t curr{};
    std::cin >> curr;
    for (std::uint64_t day{0};; day++) {
      // std::cout << "[DEBUG] curr = " << curr << "\n";
      if (!num_map_to_grp.contains(curr)) {
        curr = get_next(curr);
        // std::cout << "[DEBUG] curr after not found = " << curr << "\n";
        continue;
      }
      // std::cout << "[DEBUG] grp found " << num_map_to_grp.at(curr) << "\n";
      handle_grps(curr, day);
      break;
    }
  }

  std::uint64_t ans{0};
  for (const auto& val : grp_sizes) {
    ans += (val * (val - 1)) / 2;
  }
  std::cout << ans << "\n";
}

void solve() noexcept {
  std::uint16_t tests{};
  std::cin >> tests;

  while (tests > 0) {
    tests--;
    test();
  }
}