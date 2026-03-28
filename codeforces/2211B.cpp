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

#include <cstdint>
#include <cstdlib>
#include <iostream>

constexpr int MOD = 676767677;

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    int num_1{};
    int num_neg_1{};
    std::cin >> num_1 >> num_neg_1;

    int sum = num_1 - num_neg_1;
    std::int64_t ans = 0;

    if (sum == 0) {
      ans = 1;
    } else {
      int abs_sum = std::abs(sum);
      for (int i{1}; i * i <= abs_sum; i++) {
        if (abs_sum % i == 0) {
          ans++;
          if (i != abs_sum / i) {
            ans++;
          }
        }
      }
    }

    std::cout << ans % MOD << "\n";

    for (int i{0}; i < num_1; i++) {
      std::cout << 1 << " ";
    }
    for (int i{0}; i < num_neg_1; i++) {
      std::cout << -1 << " ";
    }
    std::cout << "\n";
  }
}