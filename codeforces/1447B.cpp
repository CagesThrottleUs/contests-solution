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
#include <limits>
void solve() {
  int tests{};
  std::cin >> tests;
  while ((tests--) != 0) {
    int grid_size{};
    int col_size{};
    std::cin >> grid_size >> col_size;

    int abs_sum{0};
    int cnt_neg{0};
    int min_val{std::numeric_limits<int>::max()};

    for (int i = 0; i < grid_size; i++) {
      for (int j = 0; j < col_size; j++) {
        int val{};
        std::cin >> val;
        if (val < 0) {
          cnt_neg++;
        }
        val = std::abs(val);
        abs_sum += val;
        min_val = std::min(min_val, val);
      }
    }

    if ((cnt_neg & 1) == 1) {  // NOLINT(hicpp-signed-bitwise)
      abs_sum -= 2 * min_val;
    }

    std::cout << abs_sum << "\n";
  }
}