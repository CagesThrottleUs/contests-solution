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
#include <vector>

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    std::size_t total_pivots{};
    std::cin >> size >> total_pivots;

    std::vector<int> arr(size + 1);
    for (std::size_t i = 1; i <= size; ++i) {
      std::cin >> arr[i];
    }

    std::vector<std::size_t> pivots(total_pivots);
    for (std::size_t i = 0; i < total_pivots; ++i) {
      std::cin >> pivots[i];
    }

    // Target value x is the value at any special index
    int target = arr[pivots[0]];

    // Construct difference array d of (a[i] ^ x)
    // d[i] = 1 means a change in state relative to the target
    std::vector<int> diff(size + 2, 0);
    for (std::size_t i = 1; i <= size; ++i) {
      // NOLINTNEXTLINE(hicpp-signed-bitwise)
      int current = arr[i] ^ target;
      // NOLINTNEXTLINE(hicpp-signed-bitwise)
      int prev = (i == 1) ? 0 : (arr[i - 1] ^ target);
      // NOLINTNEXTLINE(hicpp-signed-bitwise)
      diff[i] = current ^ prev;
    }
    // NOLINTNEXTLINE(hicpp-signed-bitwise)
    diff[size + 1] = arr[size] ^ target;

    // Count 1s in each "bin" separated by special indices
    // Bin logic: Index i belongs to Bin j if p[j-1] < i <= p[j]
    std::vector<int> bin_counts(total_pivots + 1, 0);
    std::size_t current_bin = 0;
    int total_ones = 0;

    for (std::size_t i = 1; i <= size + 1; ++i) {
      // NOLINTNEXTLINE(hicpp-signed-bitwise)
      if (diff[i] == 1) {
        // Move to the correct bin for index i
        while (current_bin < total_pivots &&
               i > pivots[current_bin]) {
          current_bin++;
        }
        bin_counts[current_bin]++;
        total_ones++;
      }
    }

    int max_bin = 0;
    for (int count : bin_counts) {
      max_bin = std::max(max_bin, count);
    }

    // The answer is the classic "pair different colors" result
    std::cout << std::max(total_ones / 2, max_bin) << "\n";
  }
}