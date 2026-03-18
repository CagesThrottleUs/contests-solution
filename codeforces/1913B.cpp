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

#include <iostream>
#include <string>

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::string str{};
    std::cin >> str;

    int ones{0};
    int zeros{0};
    for (auto &item : str) {
      if (item == '1') {
        ones++;
      } else {
        zeros++;
      }
    }

    int len_t{0};

    for (std::size_t i{0}; i < str.size(); i++) {
      if (str[i] == '1' and zeros > 0) {
        len_t++;
        zeros--;
      } else if (str[i] == '0' and ones > 0) {
        len_t++;
        ones--;
      } else {
        break;
      }
    }
    
    std::cout << static_cast<int>(str.size()) - len_t << "\n";
  }
}