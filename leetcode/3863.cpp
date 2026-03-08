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
// #include <iostream>
#include <iterator>
#include <ranges>
#include <string>

class Solution {
 public:
  auto minOperations(std::string str) -> int {
    if (str.length() == 1) {
      return 0;
    }
    auto first_check = std::ranges::is_sorted(str);
    if (first_check) {
      return 0;
    }

    if (str.length() == 2) {
      return -1;
    }

    // std::cout << "finding pos\n";

    auto min_pos = static_cast<std::size_t>(
        std::distance(str.begin(), std::ranges::min_element(str)));
    auto max_pos =
        str.size() - 1 -
        static_cast<std::size_t>(std::distance(
            str.rbegin(),
            std::ranges::max_element(std::ranges::reverse_view(str))));

    // std::cout << "min_pos: " << min_pos << "\n";
    // std::cout << "max_pos: " << max_pos << "\n";

    if (min_pos == 0 and max_pos == str.size() - 1) {
      return 1;
    }

    if (min_pos == 0) {
      return 1;
    }

    if (max_pos == str.size() - 1) {
      return 1;
    }

    if (max_pos == 0 and min_pos == str.size() - 1) {
      return 3;
    }

    return 2;
  }
};