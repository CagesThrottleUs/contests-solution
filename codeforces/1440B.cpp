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

inline auto ceil(int numerator, int denominator) -> int {
  return (numerator / denominator) +
         static_cast<int>((numerator % denominator) != 0);
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    int arr_size{};
    int total_arr{};

    std::cin >> arr_size >> total_arr;

    // std::cout << "n: " << n << "\n";
    // std::cout << "k: " << k << "\n";

    auto skip_cnt = (ceil(arr_size, 2) - 1) * total_arr;
    // std::cout << "skip_cnt: " << skip_cnt << "\n";
    auto gap = arr_size - (skip_cnt / total_arr);
    // std::cout << "gap: " << gap << "\n";

    {
      auto loop_size = skip_cnt;

      while (loop_size > 0) {
        int num{};
        std::cin >> num;
        // std::cout << "skipped: " << num << "\n";
        loop_size--;
      }
    }

    int last{skip_cnt + 1};
    std::int64_t sum{0};

    for (int i{skip_cnt + 1}; i <= (arr_size * total_arr); i++) {
      int num{};
      std::cin >> num;
      // std::cout << "num: " << num << "\n";
      if (((i - last) % gap) == 0) {
        // std::cout << "adding: " << num << "\n";
        last = i;
        sum += num;
      }
      // std::cout << "i: " << i << "\n";
      // std::cout << "n*k: " << (n * k) << "\n";
    }

    std::cout << sum << "\n";
  }
}