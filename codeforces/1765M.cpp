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

#include <iostream>
#include <numeric>

auto find_optimal_a(int num) -> int {
  int optimal_a{1};
  int running_gcd{1};
  for (int i{1}; i <= (num / 2); i++) {
    auto curr_gcd = std::gcd(i, num - i);
    if (curr_gcd > running_gcd) {
      running_gcd = curr_gcd;
      optimal_a = i;
    }
  }
  return optimal_a;
}

auto find_largest_divisor(int num) -> int {
  for (int i{2}; i * i <= num; i++) {
    if (num % i == 0) {
      return i;
    }
  }
  return 1;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    int num{};
    std::cin >> num;

    int original_num{num};

    auto ans = num/find_largest_divisor(num);

    if (ans == num) {
      ans = 1;
    }

    std::cout << ans << " " << original_num - ans << "\n";
  }
}