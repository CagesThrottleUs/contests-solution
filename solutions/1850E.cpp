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

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

constexpr std::int64_t UPPER_BOUND = 1e9;

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    std::int64_t total_area{};
    std::cin >> size >> total_area;

    std::vector<std::int64_t> lengths;
    lengths.reserve(size);

    for (std::size_t i{0}; i < size; i++) {
      std::int64_t length{};
      std::cin >> length;
      lengths.push_back(length);
    }

    std::int64_t left{0};
    std::int64_t right{UPPER_BOUND};

    std::int64_t ans{0};

    while (left <= right) {
      std::int64_t mid = left + ((right - left) / 2);
      std::int64_t area{0};

      for (const auto& length : lengths) {
        area += (length + (2 * mid)) * (length + (2 * mid));
        if (area > total_area) {
          break;
        }
      }

      if (area <= total_area) {
        ans = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    std::cout << ans << "\n";
  }
}
