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

void solve() {
  int n, m;
  std::cin >> n >> m;

  int allowed_upper = n - (n / 2);

  if (m <= allowed_upper) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}
