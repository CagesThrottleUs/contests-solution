#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

void solve_test() noexcept {
  std::size_t median_idx{};
  std::cin >> median_idx;

  const auto total_size = 2 * median_idx;

  std::vector<std::uint32_t> arr;
  arr.reserve(total_size);

  for (std::size_t i{0}; i < total_size; i++) {
    std::uint32_t num{};
    std::cin >> num;

    arr.emplace_back(num);
  }

  std::ranges::sort(arr);

  std::cout << arr[median_idx] - arr[median_idx - 1] << "\n";
}

void solve() noexcept {
  std::size_t tests{};
  std::cin >> tests;

  while (tests > 0) {
    tests--;
    solve_test();
  }
}