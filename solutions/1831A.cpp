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

void find_permutation() {
  int n{};
  std::cin >> n;

  int temp{};
  bool first{true};

  for (int i{0}; i < n; i++) {
    std::cin >> temp;
    if (first) {
      first = false;
      std::cout << n - temp + 1;
    } else {
      [[likely]] std::cout << " " << n - temp + 1;
    }
  }
  std::cout << "\n";
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    find_permutation();
  }
}
