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
#include <limits>

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t first{};
    std::size_t second{};
    std::cin >> first >> second;

    if (first < second) {
      std::cout << "1\n";
      continue;
    }

    if (first == second) {
      std::cout << "2\n";
      continue;
    }

    std::size_t ops{std::numeric_limits<std::size_t>::max()};
    std::size_t start_step{0};
    if (second == 1) {
      start_step = 1;
    }

    std::size_t total_ops_in_loop{0};

    std::size_t original_second{second};
    std::size_t original_first{first};

    while (ops >= total_ops_in_loop and
           (original_first >= original_second + start_step)) {
      total_ops_in_loop = start_step;
      second = original_second + start_step;
      first = original_first;
      while (first > 0) {
        first = first / second;
        total_ops_in_loop++;
      }
      ops = std::min(ops, total_ops_in_loop);
      start_step++;
    }

    std::cout << ops << "\n";
  }
}