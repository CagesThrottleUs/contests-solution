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
    std::size_t arr_size{};
    std::cin >> arr_size;

    std::vector<std::int32_t> reduced;
    reduced.reserve(arr_size);
    std::int32_t last_diff{0};

    for (std::size_t i{0}; i < arr_size; i++) {
      std::int32_t num{};
      std::cin >> num;
      if (reduced.empty()) {
        reduced.push_back(num);
        continue;
      }
      auto diff = num - reduced.back();
      if ((reduced.size() >= 2) and
          ((last_diff > 0 and diff > 0) or (last_diff < 0 and diff < 0))) {
        reduced.back() = num;
        last_diff += diff;
        continue;
      }
      if (diff == 0) {
        continue;
      }
      reduced.push_back(num);
      last_diff = diff;
    }

    std::cout << reduced.size() << "\n";
  }
}