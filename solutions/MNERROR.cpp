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

void solve() {
  int T;
  std::cin >> T;
  while (T--) {
    long long N, Q;
    std::cin >> N >> Q;
    // f(e,q) = (2e+1)(Q+1) is max N handleable with error e and q queries
    // Min e s.t. (2e+1)(Q+1) >= N
    // => 2e+1 >= ceil(N/(Q+1))
    // => e = ceil((ceil(N/(Q+1)) - 1) / 2) = ceil(N/(Q+1)) / 2  (integer
    // division)
    long long denom = Q + 1;
    long long c = (N + denom - 1) / denom; // ceil(N / (Q+1))
    long long ans = c / 2;
    std::cout << ans << '\n';
  }
}
