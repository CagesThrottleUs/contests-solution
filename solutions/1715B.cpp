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
#include <vector>
void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::uint64_t total_nums{};
    std::uint64_t divisor{};
    std::uint64_t beauty{};
    std::uint64_t sum{};

    std::cin >> total_nums >> divisor >> beauty >> sum;

    if (sum < (divisor * beauty) ||
        sum > ((divisor * beauty) + ((divisor - 1) * (total_nums)))) {
      std::cout << "-1\n";
      continue;
    }

    std::vector<std::uint64_t> nums(total_nums);
    nums[0] = (divisor * beauty);
    std::uint64_t to_give = sum - (divisor * beauty);

    for (std::size_t i = 0; i < total_nums && to_give > 0; i++) {
      std::uint64_t give = std::min(to_give, divisor - 1);
      nums[i] += give;
      to_give -= give;
    }

    std::cout << nums[0];
    for (std::size_t i{1}; i < total_nums; i++) {
      std::cout << " " << nums[i];
    }
    std::cout << "\n";
  }
}
