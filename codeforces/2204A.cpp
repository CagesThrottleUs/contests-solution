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

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t str_len{};
    std::cin >> str_len;

    std::string str{};
    str.reserve(str_len);
    std::cin >> str;

    int curr_pos{1};
    int max_pos{0};

    for (std::size_t i{0}; i < str_len; i++) {
      if (str[static_cast<std::size_t>(curr_pos) - 1] == 'R') {
        curr_pos++;
      } else {
        curr_pos--;
      }
      max_pos = std::max(max_pos, curr_pos);
    }
    std::cout << max_pos << "\n";
  }
}