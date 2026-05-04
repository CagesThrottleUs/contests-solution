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

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

void solve() {
  std::int32_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    std::cin >> size;

    std::vector<std::int32_t> nums;
    nums.reserve(size);

    std::set<std::int32_t> nums_set;

    for (std::size_t i{0}; i < size; i++) {
      std::int32_t num{};
      std::cin >> num;
      nums.push_back(num);
      nums_set.insert(num);
    }

    std::size_t start{0};
    std::size_t end{size - 1};

    while (start < end) {
      auto max_val = *nums_set.rbegin();
      auto min_val = *nums_set.begin();

      bool good_start{true};
      bool good_end{true};

      if (nums[start] == max_val or nums[start] == min_val) {
        nums_set.erase(nums[start]);
        start++;
        good_start = false;
      }

      if (nums[end] == max_val or nums[end] == min_val) {
        nums_set.erase(nums[end]);
        end--;
        good_end = false;
      }

      if (good_start and good_end) {
        break;
      }
    }

    if (start >= end) {
      std::cout << "-1\n";
      continue;
    }

    std::cout << start + 1 << " " << end + 1 << "\n";
  }
}