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

auto work() -> int {
  int n{};
  std::cin >> n;

  int sum{0};
  for (int i{0}; i < n; i++) {
    int input{};
    std::cin >> input;
    sum += input;
  }
  return sum;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    auto sum = work();

    if ((sum & 1) == 1) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
    }
  }
}
