#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

void solve() noexcept {
  std::uint16_t friends{};
  std::cin >> friends;

  std::size_t idx{0};
  std::vector<std::size_t> rev_idx(friends, 0);

  while (friends > 0) {
    friends--;

    std::size_t receiver{};
    std::cin >> receiver;

    rev_idx[receiver - 1] = idx + 1;

    idx++;
  }

  for (const auto& idc : rev_idx) {
    std::cout << idc << " ";
  }
  std::cout << '\n';
}