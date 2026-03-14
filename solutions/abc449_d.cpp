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

#include <algorithm>
#include <cstdint>
#include <iostream>

namespace {

// Count of even integers in [low, high].
// NOLINTNEXTLINE(bugprone-easily-swappable-parameters) - down, upper order
constexpr auto count_even_in_range(std::int64_t low, std::int64_t high)
    -> std::int64_t {
  if (low > high) {
    return 0;
  }
  // First even >= low: low if low even, else low+1.
  std::int64_t first = (low % 2 == 0) ? low : (low + 1);
  // Last even <= high: high if high even, else high-1.
  std::int64_t last = (high % 2 == 0) ? high : (high - 1);
  if (first > last) {
    return 0;
  }
  return ((last - first) / 2) + 1;
}

// Count of y in [down, upper] with |y| <= abs_val.
// NOLINTNEXTLINE(bugprone-easily-swappable-parameters) - down, upper order
constexpr auto count_abs_le(std::int64_t down, std::int64_t upper,
                            std::int64_t abs_val) -> std::int64_t {
  std::int64_t low = std::max(down, -abs_val);
  std::int64_t high = std::min(upper, abs_val);
  if (low > high) {
    return 0;
  }
  return high - low + 1;
}

// Count of y in [down, upper] with |y| > abs_val and y even.
constexpr std::int64_t count_abs_gt_even(std::int64_t down, std::int64_t upper,
                                         std::int64_t abs_val) {
  return count_even_in_range(abs_val + 1, upper) +
         count_even_in_range(down, -abs_val - 1);
}

// Count of black y in [down, upper] for fixed x (with abs_x = |x|).
// Black <=> max(|x|,|y|) even <=> (|x| even and (|y|<=|x| or (|y|>|x| and
// |y| even))) or (|x| odd and |y|>|x| and |y| even).
constexpr auto count_black_y(std::int64_t down, std::int64_t upper,
                                     std::int64_t abs_x) -> std::int64_t {
  if (abs_x % 2 == 0) {
    return count_abs_le(down, upper, abs_x) +
           count_abs_gt_even(down, upper, abs_x);
  }
  return count_abs_gt_even(down, upper, abs_x);
}

}  // namespace

void solve() {
  std::int64_t left{};
  std::int64_t right{};
  std::int64_t down{};
  std::int64_t upper{};

  std::cin >> left >> right >> down >> upper;

  std::int64_t ans{0};
  for (std::int64_t x_val{left}; x_val <= right; ++x_val) {
    std::int64_t abs_x = (x_val >= 0) ? x_val : -x_val;
    ans += count_black_y(down, upper, abs_x);
  }

  std::cout << ans << "\n";
}
