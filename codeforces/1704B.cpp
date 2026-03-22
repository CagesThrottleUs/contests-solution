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

auto get_phi_intersects(std::size_t arr_len, int constant) -> std::size_t {
  std::size_t cnt{0};
  int curr{};
  std::cin >> curr;
  int lower{curr - constant};
  int upper{curr + constant};
  for (std::size_t i{2}; i <= arr_len; i++) {
    std::cin >> curr;
    int next_lower{curr - constant};
    int next_upper{curr + constant};
    lower = std::max(lower, next_lower);
    upper = std::min(upper, next_upper);
    if (lower > upper) {
      cnt++;
      lower = next_lower;
      upper = next_upper;
    }
  }
  return cnt;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t arr_len{};
    std::cin >> arr_len;
    int constant{};
    std::cin >> constant;

    auto cnt = get_phi_intersects(arr_len, constant);
    std::cout << cnt << "\n";
  }
}