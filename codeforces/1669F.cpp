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
#include <iterator>
#include <vector>

void solve() {
  std::int32_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    std::cin >> size;

    std::vector<std::uint32_t> arr;
    std::vector<std::uint32_t> prefix_sum;
    arr.reserve(size);
    prefix_sum.reserve(size);
    std::uint32_t sum{0};

    for (std::size_t i{0}; i < size; i++) {
      std::uint32_t num{};
      std::cin >> num;
      arr.push_back(num);
      sum += num;
      prefix_sum.push_back(sum);
    }

    sum = 0;

    std::size_t max_eaten{0};

    for (std::size_t i{arr.size() - 1}; i < arr.size(); i--) {
      sum += arr[i];
      auto last = prefix_sum.begin() + static_cast<std::ptrdiff_t>(i);
      auto res = std::equal_range(prefix_sum.begin(), last, sum);

      if (res.first != last and *res.first == sum) {
        auto eaten = static_cast<std::size_t>(
            std::distance(prefix_sum.begin(), res.first)) + 1;
        eaten += (arr.size() - i);
        max_eaten = std::max(max_eaten, eaten);
      }
    }

    std::cout << max_eaten << "\n";
  }
}