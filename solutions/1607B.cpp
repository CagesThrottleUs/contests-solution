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

#include <cstdint>
#include <iostream>

constexpr std::int64_t DIVISOR{4};

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::int64_t start_pos{};
    std::int64_t steps{};
    std::cin >> start_pos >> steps;

    std::int64_t final_pos{start_pos};

    auto rem = steps % DIVISOR;

    switch (rem) {
      case 0:
        final_pos += 0;
        break;
      case 1:
        // NOLINTNEXTLINE(hicpp-signed-bitwise)
        final_pos += steps * ((start_pos & 1) == 1 ? 1 : -1);
        break;
      case 2:
        // NOLINTNEXTLINE(hicpp-signed-bitwise)
        final_pos += (start_pos & 1) == 1 ? -1 : 1;
        break;
      default:
        // NOLINTNEXTLINE(hicpp-signed-bitwise)
        final_pos += (steps + 1) * ((start_pos & 1) == 1 ? -1 : 1);
        break;
    }

    std::cout << final_pos << "\n";
  }
}
