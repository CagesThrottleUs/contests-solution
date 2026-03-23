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

#include <cstdint>
#include <iostream>

auto xor_to_n(std::uint32_t num) -> std::uint32_t {
  switch (num % 4) {
    case 0:
      return num;
    case 1:
      return 1;
    case 2:
      return num + 1;
    default:
      return 0;
  }
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::uint32_t mex{};
    std::uint32_t xor_res{};
    std::cin >> mex >> xor_res;

    std::uint32_t target_xor = xor_to_n(mex - 1) xor xor_res;
    // std::cout << "DEBUG: target_xor: " << target_xor << "\n";

    if (target_xor == 0){
      std::cout << mex << "\n";
    } else if (target_xor != mex) {
      std::cout << mex + 1 << "\n";
    } else {
      std::cout << mex + 2 << "\n";
    }
  }
}
