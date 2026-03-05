/*
 *   MIT License
 *
 *   Copyright (c) 2026 CagesThrottleUs
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
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

#include <iostream>

auto len_subarr() -> int {
  int n{};
  std::cin >> n;

  int longest_len{0};
  int cur_len{0};

  for (int i{0}; i < n; i++) {
    int num{};
    std::cin >> num;
    if (num == 0) {
      cur_len++;
      longest_len = std::max(longest_len, cur_len);
    } else {
      cur_len = 0;
    }
  }

  return longest_len;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    auto sol = len_subarr();
    std::cout << sol << "\n";
  }
}
