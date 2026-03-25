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
#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

constexpr int DISCOUNT{100};

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t num_items{};
    int max_money{};
    std::cin >> num_items >> max_money;

    std::vector<std::pair<int, int>> items(num_items, {-1, -1});

    for (std::size_t i{0}; i < num_items; i++) {
      int price{};
      std::cin >> price;
      items[i].first = price;
    }

    for (std::size_t i{0}; i < num_items; i++) {
      int discount{};
      std::cin >> discount;
      items[i].second = discount;
    }

    std::ranges::sort(items, [](const auto& lhs, const auto& rhs) -> bool {
      if (lhs.first != rhs.first) {
        return lhs.first < rhs.first;
      }
      return lhs.second < rhs.second;
    });

    std::size_t left{0};
    std::size_t right{num_items - 1};

    int max_beauty{0};

    while (left < right) {
      auto cost = items[left].first + std::max(items[right].first / 2,
                                               items[right].first - DISCOUNT);
      if (cost <= max_money) {
        auto idx = std::max_element(
            items.begin() + static_cast<std::ptrdiff_t>(left) + 1,
            items.begin() + static_cast<std::ptrdiff_t>(right) + 1,
            [](const auto& lhs, const auto& rhs) -> bool {
              return lhs.second < rhs.second;
            });
        max_beauty =
            std::max(max_beauty, items[left].second + idx->second);
        left++;
      } else {
        right--;
      }
    }

    std::cout << max_beauty << "\n";
  }
}