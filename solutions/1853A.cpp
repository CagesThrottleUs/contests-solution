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

#include <iostream>
#include <limits>

auto work() -> int {
  int n{};
  std::cin >> n;

  int last{};
  std::cin >> last;

  bool is_sorted{true};
  int min_diff = std::numeric_limits<int>::max();

  for (int i{1}; i < n; i++) {
    int curr{};
    std::cin >> curr;
    is_sorted &= (last <= curr);
    min_diff = std::min(min_diff, curr - last);
    last = curr;
  }

  if (!is_sorted)
    return 0;

  return (min_diff / 2) + 1;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    auto sol = work();
    std::cout << sol << "\n";
  }
}
