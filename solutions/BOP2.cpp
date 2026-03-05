/*
 *   Copyright (c) 2026 CagesThrottleUs
 *   All rights reserved.
 */
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

/*
 *   Copyright (c) 2026 CagesThrottleUs
 *   All rights reserved.
 */
#include <iostream>
#include <unordered_set>

auto count_uniques() -> int {
  int n{};
  std::cin >> n;

  std::unordered_set<int> unique_elements;
  for (int i{0}; i < n; i++) {
    int input{};
    std::cin >> input;
    unique_elements.insert(input);
  }
  return unique_elements.size();
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    auto uniques = count_uniques();
    std::cout << uniques << "\n";
  }
}
