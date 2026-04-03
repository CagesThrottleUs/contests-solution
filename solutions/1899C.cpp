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

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iostream>

enum class Parity : std::uint8_t {
  ODD,
  EVEN,
};

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    std::cin >> size;

    int last{};
    std::cin >> last;
    Parity last_parity{Parity::EVEN};
    // NOLINTNEXTLINE(hicpp-signed-bitwise)
    if ((std::abs(last) & 1) == 1) {
      last_parity = Parity::ODD;
    }
    int max_sum{last};
    int curr_sum{last};

    if (last < 0) {
      curr_sum = 0;
    }

    for (std::size_t i{2}; i <= size; i++) {
      int num{};
      std::cin >> num;

      Parity num_parity{Parity::EVEN};
      // NOLINTNEXTLINE(hicpp-signed-bitwise)
      if ((std::abs(num) & 1) == 1) {
        num_parity = Parity::ODD;
      }

      if (num_parity == last_parity) {
        curr_sum = num;
        max_sum = std::max(max_sum, curr_sum);
      } else {
        curr_sum += num;
        max_sum = std::max(max_sum, curr_sum);
      }

      curr_sum = std::max(curr_sum, 0);
      last_parity = num_parity;
      last = num;
    }

    std::cout << max_sum << "\n";
  }
}
