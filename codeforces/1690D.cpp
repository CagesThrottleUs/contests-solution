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
#include <string>

auto min_white_cnt(const std::string& strip, std::size_t segment_len) -> std::size_t {
  std::size_t left{0};
  std::size_t right{segment_len - 1};
  std::size_t white_cnt{0};
  for (std::size_t i{left}; i <= right; i++) {
    if (strip[i] == 'W') {
      white_cnt++;
    }
  }
  std::size_t min_white_cnt{white_cnt};
  while (right + 1 < strip.size()) {
    if (strip[right + 1] == 'W') {
      white_cnt++;
    }
    if (strip[left] == 'W') {
      white_cnt--;
    }
    left++;
    right++;
    min_white_cnt = std::min(min_white_cnt, white_cnt);
  }
  return min_white_cnt;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t strip_len{};
    std::cin >> strip_len;
    std::size_t segment_len{};
    std::cin >> segment_len;

    std::string strip{};
    strip.reserve(strip_len);
    std::cin >> strip;

    std::cout << min_white_cnt(strip, segment_len) << "\n";
  }
}