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
#include <numeric>

inline auto sum_upto(std::int64_t num) -> std::int64_t {
  return (num * (num + 1)) / 2;
}

void solve() {
  std::int32_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::int64_t perm_size{};
    std::cin >> perm_size;

    std::int64_t major{};
    std::int64_t minor{};
    std::cin >> major >> minor;

    auto lcm_val = std::lcm(major, minor);

    auto major_units = perm_size / major;
    auto minor_units = perm_size / minor;

    major_units -= (major_units * major) / lcm_val;
    minor_units -= (minor_units * minor) / lcm_val;

    auto ans = (sum_upto(perm_size) - sum_upto(perm_size - major_units) -
                sum_upto(minor_units));

    std::cout << ans << "\n";
  }
}