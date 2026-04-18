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
#include <vector>
void solve() {
  std::int32_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    std::cin >> size;

    std::vector<std::uint32_t> nums;
    nums.reserve(size);

    for (std::size_t i{0}; i < size; i++) {
      std::uint32_t num{};
      std::cin >> num;
      nums.push_back(num);
    }

    auto target = nums.back();

    auto ops = 0;

    for (std::size_t i{size - 1}; i < size; i--) {
      if (nums[i] == target) {
        continue;
      }

      // NEQ case
      // i+1 to n-1 are target already
      auto len = (size - 1) - (i + 1) + 1;
      ops++;
      auto new_i = i;
      if (i >= len) {
        new_i = i - len;
      } else {
        new_i = size;
      }
      i = new_i + 1;
    }

    std::cout << ops << "\n";
  }
}