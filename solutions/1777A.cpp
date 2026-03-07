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

auto total_ops(int size) -> int {
  int total_op = 0;

  int input{};
  std::cin >> input;
  int curr_cnt{1};
  int current_parity{(input & 1)};  // NOLINT(hicpp-signed-bitwise)
  for (int i = 1; i < size; i++) {
    std::cin >> input;

    int parity = input & 1;  // NOLINT(hicpp-signed-bitwise)
    if (parity != current_parity) {
      total_op += curr_cnt - 1;
      current_parity = parity;
      curr_cnt = 1;
    } else {
      curr_cnt++;
    }
  }
  total_op += curr_cnt - 1;
  return total_op;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    int size{};
    std::cin >> size;

    auto min_total_op = total_ops(size);
    std::cout << min_total_op << "\n";
  }
}
