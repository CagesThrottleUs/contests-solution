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
#include <cstdlib>
#include <iostream>
#include <limits>

void solve() {
  int n{};
  std::cin >> n;

  int min_op = std::numeric_limits<int>::max();
  for (int i = 0; i < n; i++) {
    int a{};
    std::cin >> a;
    min_op = std::min(min_op, std::abs(a));
  }
  std::cout << min_op << "\n";
}
