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

#include <array>
#include <cstdint>
#include <functional>
#include <string>

constexpr int BASE = 10;
constexpr int MAX_DIGITS = 16;
constexpr int MAX_DIGIT_SUM = (BASE - 1) * MAX_DIGITS;  // 135
constexpr int LAST_NONE = 10;

// Flat memo dimensions: pos(15) * tight(2) * last(11) * inc(2) * dec(2) *
// dsum(136)
constexpr int MEMO_SIZE =
    MAX_DIGITS * 2 * (BASE + 1) * 2 * 2 * (MAX_DIGIT_SUM + 1);

class Solution {
 public:
  Solution() { precompute(); }

  auto countFancy(std::int64_t left, std::int64_t right) -> std::int64_t {
    return solve(right) - solve(left - 1);
  }

 private:
  std::array<bool, MAX_DIGIT_SUM + 1> good_sum{};
  std::array<std::int64_t, MEMO_SIZE> memo{};
  std::array<bool, MEMO_SIZE> visited{};

  void precompute() {
    auto is_good = [](int n) -> bool {
      std::string str = std::to_string(n);
      if (str.size() == 1) {
        return true;
      }
      bool inc = true;
      bool dec = true;
      for (std::size_t i = 0; i + 1 < str.size(); ++i) {
        if (str[i] >= str[i + 1]) {
          inc = false;
        }
        if (str[i] <= str[i + 1]) {
          dec = false;
        }
      }
      return inc || dec;
    };
    for (int i = 1; i <= MAX_DIGIT_SUM; ++i) {
      good_sum.at(static_cast<std::size_t>(i)) = is_good(i);
    }
  }

  // Pack state into a single flat index for O(1) memo access
  static auto idx(int pos, int tight, int last, int inc, int dec, int dsum)
      -> int {
    return (((((pos * 2 + tight) * (BASE + 1) + last) * 2 + inc) * 2 + dec) *
            (MAX_DIGIT_SUM + 1)) +
           dsum;
  }

  // NOLINTNEXTLINE(readability-function-cognitive-complexity)
  auto solve(std::int64_t num) -> std::int64_t {
    if (num <= 0) {
      return 0;
    }

    const std::string digits = std::to_string(num);
    const int max_depth = static_cast<int>(digits.size());

    // Reset visited for this call — memo values are only valid when visited is
    // set
    visited.fill(false);

    std::function<std::int64_t(int, int, int, int, int, int)> top_down_dp =
        // NOLINTNEXTLINE(readability-function-cognitive-complexity)
        [&](int pos, int tight, int last, int inc, int dec,
            int dsum) -> std::int64_t {
      if (pos == max_depth) {
        if (last == LAST_NONE) {
          return 0;  // number was zero
        }
        if (inc || dec) {
          return 1;  // number itself is good
        }
        return good_sum.at(static_cast<std::size_t>(dsum))
                   ? 1
                   : 0;  // digit sum is good
      }

      const int key = idx(pos, tight, last, inc, dec, dsum);
      if (visited.at(static_cast<std::size_t>(key))) {
        return memo.at(static_cast<std::size_t>(key));
      }
      visited.at(static_cast<std::size_t>(key)) = true;

      auto& ans = memo.at(static_cast<std::size_t>(key));
      ans = 0;
      const int lim =
          tight ? (digits.at(static_cast<std::size_t>(pos)) - '0') : 9;

      for (int digit = 0; digit <= lim; ++digit) {
        const int new_tight = (tight && digit == lim) ? 1 : 0;

        if (last == LAST_NONE) {
          ans += top_down_dp(pos + 1, new_tight, digit == 0 ? LAST_NONE : digit,
                             1, 1, digit);
        } else {
          ans += top_down_dp(pos + 1, new_tight, digit,
                             inc && (digit > last) ? 1 : 0,
                             dec && (digit < last) ? 1 : 0, dsum + digit);
        }
      }
      return ans;
    };

    return top_down_dp(0, 1, LAST_NONE, 1, 1, 0);
  }
};
