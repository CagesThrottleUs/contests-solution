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

#include <cstdint>
#include <iostream>

void solve() {
  std::int32_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::uint32_t unit_len{};
    std::uint32_t l_shapes{};
    std::cin >> unit_len >> l_shapes;

    auto target = (2 * unit_len) + (4 * l_shapes) + 1;

    auto found = false;

    for (std::uint32_t i{3}; (i * i) <= target; i += 2) {
      if (target % i != 0) {
        continue;
      }
      auto other = target / i;
      auto len = (i - 1) / 2;
      auto width = (other - 1) / 2;

      if ((len + 1) * width >= l_shapes and (width + 1) * len >= l_shapes) {
        std::cout << len << " " << width << "\n";
        found = true;
        break;
      }
    }

    if (!found) {
      std::cout << "-1\n";
    }
  }
}