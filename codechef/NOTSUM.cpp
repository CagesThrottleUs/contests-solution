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

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    std::cin >> size;

    std::vector<std::pair<int, std::size_t>> nums;
    nums.reserve(size);

    for (std::size_t i{0}; i < size; i++) {
      int num{};
      std::cin >> num;
      nums.emplace_back(num, i);
    }

    std::nth_element(nums.begin(), nums.begin(), nums.end());
    auto first = nums.front();

    std::nth_element(nums.begin(),
                     nums.begin() + static_cast<std::ptrdiff_t>(size - 1),
                     nums.end());
    auto last = nums.back();

    std::nth_element(nums.begin(),
                     nums.begin() + static_cast<std::ptrdiff_t>(size - 2),
                     nums.end());
    auto second_last = nums[size - 2];

    if (first.first == second_last.first and last.first == second_last.first and
        second_last.first == 0) {
      std::cout << "-1\n";
    } else {
      std::cout << last.second + 1 << " " << second_last.second + 1 << " "
                << first.second + 1 << "\n";
    }
  }
}