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

inline auto get_input() -> std::vector<std::int64_t> {
  std::size_t num_people{};
  std::cin >> num_people;

  std::vector<std::int64_t> budget(num_people, 0);

  for (std::size_t i{0}; i < num_people; i++) {
    std::int64_t wish{};
    std::cin >> wish;
    budget[i] -= wish;
  }

  for (std::size_t i{0}; i < num_people; i++) {
    std::int64_t brought{};
    std::cin >> brought;
    budget[i] += brought;
  }

  return budget;
}

void solve() {
  std::uint32_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    auto budgets = get_input();

    std::ranges::sort(budgets);

    std::size_t left{0};
    std::size_t right{budgets.size() - 1};
    std::size_t ans{0};

    while (left < right) {
      if (budgets[left] + budgets[right] >= 0) {
        ans++;
        left++;
        right--;
      } else {
        left++;
      }
    }

    std::cout << ans << "\n";
  }
}