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

#include <algorithm>
#include <array>
#include <cstdint>
#include <vector>

class Solution {
  static constexpr int MOD = 1'000'000'007;
  static constexpr int MAX_VAL = 5000;
  static constexpr int MAX_DIGIT_SUM = 50;
  static constexpr int BASE = 10;

  static auto computeDigitSum(int num) -> int {
    int sum = 0;
    while (num > 0) {
      sum += num % BASE;
      num /= BASE;
    }
    return sum;
  }

 public:
  static auto countArrays(std::vector<int>& digit_sum) -> int {
    // Precompute candidates for each digit sum value in [0, kMaxVal]
    std::array<std::vector<int>, MAX_DIGIT_SUM + 1> by_sum{};
    for (int val = 0; val <= MAX_VAL; ++val) {
      int sum = computeDigitSum(val);
      if (sum <= MAX_DIGIT_SUM) {
        by_sum.at(static_cast<std::size_t>(sum)).push_back(val);
      }
    }

    const auto len = digit_sum.size();

    // cands[i] = sorted list of valid values for position i
    std::vector<std::vector<int>> cands(len);
    for (std::size_t idx = 0; idx < len; ++idx) {
      int dsum = digit_sum.at(idx);
      if (dsum < 0 || dsum > MAX_DIGIT_SUM) {
        return 0;
      }
      cands.at(idx) = by_sum.at(static_cast<std::size_t>(dsum));
      if (cands.at(idx).empty()) {
        return 0;
      }
    }

    // ways[k] = number of arrays up to current position ending with cands[i][k]
    // Position 0: all candidates valid, each has exactly 1 way
    std::vector<std::int64_t> ways(cands.at(0).size(), 1);

    for (std::size_t idx = 1; idx < len; ++idx) {
      const auto& prev = cands.at(idx - 1);
      const auto& curr = cands.at(idx);

      // Build prefix sums over prev so we can query "sum of ways[j] for prev[j]
      // <= x"
      std::vector<std::int64_t> prefix(prev.size() + 1, 0);
      for (std::size_t jdx = 0; jdx < prev.size(); ++jdx) {
        prefix.at(jdx + 1) = (prefix.at(jdx) + ways.at(jdx)) % MOD;
      }

      std::vector<std::int64_t> newWays(curr.size(), 0);
      for (std::size_t kdx = 0; kdx < curr.size(); ++kdx) {
        // Count prev candidates <= curr[kdx] via binary search (prev is sorted)
        auto iter = std::ranges::upper_bound(prev, curr.at(kdx));
        auto cnt = static_cast<std::size_t>(iter - prev.begin());
        newWays.at(kdx) = prefix.at(cnt);
      }

      ways = std::move(newWays);
    }

    std::int64_t ans = 0;
    for (auto way : ways) {
      ans = (ans + way) % MOD;
    }
    return static_cast<int>(ans);
  }
};