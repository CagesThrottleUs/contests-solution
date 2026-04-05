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
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    int num_ops{};
    std::cin >> size >> num_ops;

    std::vector<int> nums;
    nums.reserve(size);

    std::uint64_t sum{0};

    for (std::size_t i{0}; i < size; i++) {
      int num{};
      std::cin >> num;
      nums.push_back(num);
      sum += static_cast<std::uint64_t>(num);
    }

    std::ranges::sort(nums);

    std::uint64_t current{0};
    for (std::size_t i{0}; i < static_cast<std::size_t>(num_ops); i++) {
      current += static_cast<std::uint64_t>(nums[nums.size() - i - 1]);
    }

    std::uint64_t ans{current};
    auto right = nums.size() - static_cast<std::size_t>(num_ops);
    auto left = static_cast<std::size_t>(0);

    while (right < nums.size()) {
      current = current - static_cast<std::uint64_t>(nums[right]) +
                static_cast<std::uint64_t>(nums[left] + nums[left + 1]);
      ans = std::min(ans, current);
      right++;
      left += 2;
    }

    std::cout << sum - ans << '\n';
  }
}
