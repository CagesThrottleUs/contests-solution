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
#include <functional>
#include <iostream>
#include <vector>

constexpr auto DISCOUNT_PRICE = 5;
constexpr auto FLAT_PRICE = 10;

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    int num_eles{};
    std::cin >> num_eles;
    int discounted_item_cnt{};
    std::cin >> discounted_item_cnt;

    std::vector<int> prices(static_cast<std::size_t>(num_eles));

    for (std::size_t i{0}; i < static_cast<std::size_t>(num_eles); i++) {
      std::cin >> prices[i];
    }

    std::ranges::sort(prices, std::greater<>());

    int total_profit{0};
    std::size_t idx{0};
    while (idx < static_cast<std::size_t>(discounted_item_cnt)) {
      if (prices[idx] <= DISCOUNT_PRICE) {
        break;
      }
      total_profit += prices[idx] - DISCOUNT_PRICE;
      idx++;
    }

    while (idx < static_cast<std::size_t>(num_eles)) {
      if (prices[idx] <= FLAT_PRICE) {
        break;
      }
      total_profit += prices[idx] - FLAT_PRICE;
      idx++;
    }

    std::cout << total_profit << "\n";
  }
}
