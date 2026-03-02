#include <iostream>

#ifdef __GNUC__
#ifndef __clang__
#pragma GCC optimize("O3", "unroll-loops")
#endif
#endif

void speedup() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

// Forward declaration - to be implemented in problem file
void solve();

auto main() -> int {
    speedup();
    solve();
    return 0;
}

// Include the problem-specific implementation

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

void print_solution(std::vector<int> &eles) {
  auto max_ele = std::max_element(eles.begin(), eles.end());
  std::swap(eles.front(), *max_ele);
  std::cout << eles.front();
  for (std::size_t i = 1; i < eles.size(); i++) {
    std::cout << " " << eles[i];
  }
  std::cout << "\n";
}

void solve() {
  int test_cases{};
  std::cin >> test_cases;
  while (test_cases--) {
    std::size_t num_eles{};
    std::cin >> num_eles;
    std::vector<int> eles(num_eles);
    for (std::size_t i = 0; i < num_eles; i++) {
      std::cin >> eles[i];
    }
    print_solution(eles);
  }
}
