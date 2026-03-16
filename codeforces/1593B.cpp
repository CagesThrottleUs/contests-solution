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
#include <iostream>
#include <limits>
#include <string>

auto find_min_moves(const std::string& str, char digit1, std::size_t first_pos,
                    char digit2) -> std::size_t {
  if (first_pos != std::string::npos) {
    auto first_dig = str.find(digit1, first_pos + 1);
    auto second_dig = str.find(digit2, first_pos + 1);

    auto ans = std::numeric_limits<std::size_t>::max();

    if (first_dig != std::string::npos) {
      ans = std::min(ans, first_dig - 1);
    }
    if (second_dig != std::string::npos) {
      ans = std::min(ans, second_dig - 1);
    }

    return ans;
  }
  return std::numeric_limits<std::size_t>::max();
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::string str{};
    std::cin >> str;
    std::ranges::reverse(str);

    auto first_zero = str.find('0');
    auto first_five = str.find('5');

    std::size_t ans{std::numeric_limits<std::size_t>::max()};

    ans = std::min(ans, find_min_moves(str, '0', first_zero, '5'));

    ans = std::min(ans, find_min_moves(str, '7', first_five, '2'));

    std::cout << ans << "\n";
  }
}