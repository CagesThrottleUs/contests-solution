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

void work() {
  int x{}, k{};
  std::cin >> x >> k;

  int rem = (x % k);

  if (rem == 0) {
    std::cout << "2\n";
    std::cout << x - 1 << " " << 1 << "\n";
  } else {
    std::cout << "1\n";
    std::cout << x << "\n";
  }
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    work();
  }
}
