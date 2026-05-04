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
#include <cstdint>
#include <iostream>
#include <vector>
void solve() {
  std::int32_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t cards{};
    std::size_t num_per_card{};
    std::cin >> cards >> num_per_card;

    std::vector<std::vector<std::int32_t>> card_map(
        num_per_card, std::vector<std::int32_t>(cards, 0));

    for (std::size_t i{0}; i < cards; i++) {
      for (std::size_t j{0}; j < num_per_card; j++) {
        std::int32_t num{};
        std::cin >> num;
        card_map[j][i] = num;
      }
    }

    std::int64_t ans{0};

    for (std::size_t i{0}; i < card_map.size(); i++) {
      auto& col = card_map[i];
      std::ranges::sort(col);
      std::int64_t prefix_sum{0};
      for (std::size_t j{0}; j < col.size(); j++) {
        ans += (static_cast<std::int64_t>(j) * col[j]) - prefix_sum;
        prefix_sum += col[j];
      }
    }

    std::cout << ans << "\n";
  }
}