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
#include <limits>
#include <utility>
#include <vector>

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t total_nums{};
    std::cin >> total_nums;

    std::vector<std::pair<std::uint64_t, std::uint64_t>> nums;
    nums.reserve(total_nums);

    for (std::size_t i{0}; i < total_nums; i++) {
      std::uint64_t num{};
      std::cin >> num;
      nums.emplace_back(num, i);
    }

    std::ranges::sort(nums);

    std::vector<std::uint64_t> prefix_sums;
    prefix_sums.reserve(total_nums);

    std::uint64_t sum{0};
    for (auto [num, idx] : nums) {
      sum += num;
      prefix_sums.emplace_back(sum);
    }

    std::vector<std::uint64_t> ans(total_nums);

    for (std::size_t i{0}; i < total_nums; i++) {
      auto idx = i;
      auto found = i;

      while (idx < total_nums) {
        std::pair<std::uint64_t, std::uint64_t> temp = {
            prefix_sums[idx] + 1, std::numeric_limits<std::uint64_t>::min()};
        auto next = std::ranges::lower_bound(nums, temp) - nums.begin();
        next--;
        if (static_cast<std::size_t>(next) == idx) {
          break;
        }
        found += static_cast<std::size_t>(next) - idx;
        idx = static_cast<std::size_t>(next);
      }

      ans[nums[i].second] = found;
    }

    std::cout << ans[0];
    for (std::size_t i{1}; i < total_nums; i++) {
      std::cout << " " << ans[i];
    }
    std::cout << "\n";
  }
}
