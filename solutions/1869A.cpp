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

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3", "unroll-loops")
#elif defined(__clang__)
#pragma clang optimize on
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
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    int ele_cnt{};
    std::cin >> ele_cnt;

    int xor_res{0};
    for (int i{0}; i < ele_cnt; i++) {
      int input{};
      std::cin >> input;
      xor_res = xor_res xor input;  // NOLINT(hicpp-signed-bitwise)
    }

    if (xor_res == 0) {
      std::cout << "1\n1 " << ele_cnt << "\n";
    } else {
      if ((ele_cnt & 1) == 0) {  // NOLINT(hicpp-signed-bitwise)
        std::cout << "2\n1 " << ele_cnt << "\n1 " << ele_cnt << "\n";
      } else {
        std::cout << "4\n1 " << ele_cnt << "\n1 " << ele_cnt - 1 << "\n"
                  << ele_cnt - 1 << " " << ele_cnt << "\n"
                  << ele_cnt - 1 << " " << ele_cnt << "\n";
      }
    }
  }
}
