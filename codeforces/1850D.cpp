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
#include <vector>

// Minimum removals = n - (longest contiguous segment in sorted order with
// every consecutive diff <= k). Find that segment in one pass.
auto min_removals(const std::vector<int>& arr, int max_diff) -> std::size_t {
  if (arr.empty()) {
    return 0;
  }
  std::size_t run_start{0};
  std::size_t max_run{1};
  for (std::size_t i{1}; i < arr.size(); ++i) {
    if (static_cast<int>(arr[i] - arr[i - 1]) > max_diff) {
      run_start = i;
    }
    max_run = std::max(max_run, i - run_start + 1);
  }
  return arr.size() - max_run;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    int elements{};
    int max_diff{};
    std::cin >> elements >> max_diff;

    std::vector<int> arr;
    arr.reserve(static_cast<std::size_t>(elements));
    for (int i{0}; i < elements; i++) {
      int element{};
      std::cin >> element;
      arr.push_back(element);
    }

    std::ranges::sort(arr);

    std::cout << min_removals(arr, max_diff) << "\n";
  }
}