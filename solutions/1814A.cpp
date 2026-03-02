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

auto work() -> bool {
  long long n{}, k{};
  std::cin >> n >> k;

  if (n % 2 == 0) {
    return true;
  }

  auto rem = n % k;
  if ((rem & 1) == 1 and (k & 1) == 0) {
    return false;
  }
  return true;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    auto sol = work();
    std::cout << (sol ? "YES" : "NO") << "\n";
  }
}
