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
#include <cstdint>
#include <iostream>

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    int max_timer{};
    int curr_timer{};
    std::cin >> max_timer >> curr_timer;

    std::int64_t total_time{0};
    total_time += (curr_timer - 1);

    int tools_cnt{};
    std::cin >> tools_cnt;

    for (int i{0}; i < tools_cnt; i++) {
      int tool_timer{};
      std::cin >> tool_timer;

      total_time += 1;
      curr_timer = std::min(1 + tool_timer, max_timer) - 1;
      total_time += (curr_timer - 1);
    }

    total_time += 1;

    std::cout << total_time << "\n";
  }
}