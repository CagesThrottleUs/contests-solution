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
#include <iostream>
#include <vector>

void solve() {
  std::size_t num_ele{};
  int queries{};
  std::cin >> num_ele >> queries;

  std::vector<int> nums(num_ele);
  for (auto& num : nums) {
    std::cin >> num;
  }

  std::ranges::sort(nums);

  // Precompute sorted consecutive diffs and their suffix sums.
  // |S_X| = (span + X) - sum_{diff > X}(diff - X)
  //        = span + X*(1 + count_large) - sum_large_diffs
  std::vector<std::int64_t> diffs;
  diffs.reserve(num_ele > 0UZ ? num_ele - 1 : 0UZ);
  for (std::size_t i{1}; i < num_ele; i++) {
    diffs.push_back(static_cast<std::int64_t>(nums[i]) - nums[i - 1]);
  }
  std::ranges::sort(diffs);

  // suffix_sum[i] = sum of diffs[i..end]
  std::vector<std::int64_t> suffix_sum(diffs.size() + 1, 0LL);
  for (std::size_t i{diffs.size()}; i-- > 0UZ;) {
    suffix_sum[i] = suffix_sum[i + 1] + diffs[i];
  }

  const std::int64_t span =
      static_cast<std::int64_t>(nums.back()) - nums.front();

  while ((queries--) != 0) {
    std::int64_t qval{};
    std::cin >> qval;

    // Binary search: first diff strictly greater than qval
    const auto bound_iter = std::ranges::upper_bound(diffs, qval);
    const auto idx = static_cast<std::size_t>(bound_iter - diffs.begin());

    const auto count_large = static_cast<std::int64_t>(diffs.size() - idx);
    const std::int64_t sum_large = suffix_sum[idx];

    std::cout << span + (qval * (1LL + count_large)) - sum_large << "\n";
  }
}
