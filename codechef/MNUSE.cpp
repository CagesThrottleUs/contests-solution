/*
 *   MIT License
 *
 *   Copyright (c) 2026 CagesThrottleUs
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */
#include <algorithm>
#include <cstdint>
#include <iostream>

void process() {
  std::int64_t total_cakes{};
  std::int64_t total_items{};
  std::int64_t total_weight{};
  std::int64_t cake_to_minimize{};
  if (!(std::cin >> total_cakes >> total_items >> total_weight >>
        cake_to_minimize)) {
    return;
  }

  if (cake_to_minimize == 1) {
    // To minimize M=1, maximize use of weights in [2, N]
    // Min weight with q cakes of type 1: q(1) + (K-q)(2) = 2K - q
    // S >= 2K - q  =>  q >= 2K - S
    std::cout << std::max(0LL, (2 * total_items) - total_weight) << "\n";
  } else if (cake_to_minimize == total_cakes) {
    // To minimize M=N, maximize use of weights in [1, N-1]
    // Max weight with q cakes of type N: q(N) + (K-q)(N-1) = q + K(N-1)
    // S <= q + K(N-1) => q >= S - K(N-1)
    std::cout << std::max(0LL, total_weight - (total_items * (total_cakes - 1)))
              << "\n";
  } else {
    // For 1 < M < N, check if it's possible to have 0 cakes of type M.
    // Let k2 be the number of cakes with weight >= M+1.
    // Total weight S must be within:
    // [ (K-k2)*1 + k2*(M+1), (K-k2)*(M-1) + k2*N ]

    auto numL = total_weight - (total_items * (cake_to_minimize - 1));
    auto denL = total_cakes - cake_to_minimize + 1;

    // Lower bound for k2: ceil(numL / denL)
    auto lower_bound = (numL <= 0) ? 0 : (numL + denL - 1) / denL;

    // Upper bound for k2: floor((S - K) / M)
    auto upper_bound = (total_weight - total_items) / cake_to_minimize;

    // Check if there exists an integer k2 in [L, R] such that 0 <= k2 <= K
    auto actual_L = std::max(0LL, lower_bound);
    auto actual_R = std::min(total_items, upper_bound);

    if (actual_L <= actual_R) {
      std::cout << 0 << "\n";
    } else {
      std::cout << 1 << "\n";
    }
  }
}

void solve() {
  int tests{};
  if (!(std::cin >> tests)) {
    return;
  }
  while ((tests--) != 0) {
    process();
  }
}