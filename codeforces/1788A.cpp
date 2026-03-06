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
#include <iterator>
#include <vector>

auto find_expected() -> int {
  int n{};
  std::cin >> n;

  std::vector<std::size_t> cnt_2(static_cast<std::size_t>(n), 0);
  bool first{true};
  for (std::size_t i{0}; i < cnt_2.size(); i++) {
    int input{};
    std::cin >> input;
    if (first) {
      first = false;
      cnt_2[i] = input == 2 ? 1 : 0;
    } else {
      [[likely]] cnt_2[i] = cnt_2[i - 1] + (input == 2 ? 1 : 0);
    }
  }

  if (cnt_2.back() % 2 == 1) {
    return -1;
  }

  auto itr = std::lower_bound(cnt_2.begin(), cnt_2.end(), cnt_2.back() / 2);

  if (itr == cnt_2.end()) {
    return -1;
  }

  return static_cast<int>(std::distance(cnt_2.begin(), itr)) + 1;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    auto expected = find_expected();
    std::cout << expected << "\n";
  }
}