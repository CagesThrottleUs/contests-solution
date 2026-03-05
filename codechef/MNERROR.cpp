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