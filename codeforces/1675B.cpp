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

#include <cstddef>
#include <iostream>
#include <limits>
#include <vector>

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    std::cin >> size;

    std::vector<int> arr;
    arr.reserve(size);
    int prev{};
    std::cin >> prev;
    arr.push_back(prev);
    int violations{0};
    for (std::size_t i{1}; i < size; i++) {
      int num{};
      std::cin >> num;
      violations += static_cast<int>(prev >= num);

      arr.push_back(num);
      prev = num;
    }

    if (violations == 0) {
      std::cout << 0 << "\n";
      continue;
    }

    auto compare_against = std::numeric_limits<int>::max();
    int ops{0};

    for (std::size_t i{size - 1}; i < size; i--) {
      if (compare_against == 0) {
        ops = -1;
        break;
      }
      while (arr[i] >= compare_against) {
        ops++;
        arr[i] = arr[i] >> 1;  // NOLINT(hicpp-signed-bitwise)
      }
      // std::cout << "after arr[i]: " << arr[i] << "\n";
      compare_against = arr[i];
    }

    std::cout << ops << "\n";
  }
}