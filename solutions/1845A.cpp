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

void print(int n, int times) {
  if (times == 0) return;
  std::cout << n;
  for (int i{0}; i < times - 1; i++) {
    std::cout << " " << n;
  }
}

void work() {
  int n{}, k{}, x{};
  std::cin >> n >> k >> x;

  if ((k == 1 && x == 1) || (k == 2 && x == 1 && (n & 1))) {
    std::cout << "NO\n";
    return;
  }

  std::cout << "YES\n";
  if (x == 1) {
    int c2 = (n / 2) - (n & 1), c3 = (n & 1);
    std::cout << c2 + c3 << "\n";
    print(2, c2);
    std::cout << " ";
    print(3, c3);
  } else {
    std::cout << n << "\n";
    print(1, n);
  }
  std::cout << "\n";
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    work();
  }
}
