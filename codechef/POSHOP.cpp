#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <set>

void solve_test() noexcept {
  std::size_t size{};
  std::cin >> size;

  std::multiset<std::uint32_t> costs;
  std::uint32_t max_val{0};

  for (std::size_t i{0}; i < size; ++i) {
    std::uint32_t num{};
    std::cin >> num;

    max_val = std::max(max_val, num);

    auto itr = costs.upper_bound(num);
    if (itr != costs.begin()) {
      auto prev_val = *std::prev(itr);
      max_val = std::max(max_val, prev_val + num);
    }

    costs.insert(itr, num);
  }

  std::cout << max_val << "\n";
}

void solve() noexcept {
  std::size_t tests{};
  if (!(std::cin >> tests)) {
    return;
  }

  while (tests-- > 0) {
    solve_test();
  }
}