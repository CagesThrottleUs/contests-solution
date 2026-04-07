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
#include <vector>

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    int dummy{};
    std::cin >> size >> dummy;

    std::vector<int> arr(size);
    for (auto& val : arr) {
      std::cin >> val;
    }

    std::size_t idx{};
    std::cin >> idx;

    // Adjust to 0-based indexing safely
    int target = arr[idx - 1];
    int left{0};

    for (std::size_t i{0}; i < idx; i++) {
      if (i + 1 < idx and arr[i] != target and arr[i + 1] != target) {
        continue;
      }
      if (arr[i] != target) {
        left++;
      }
    }

    int right{0};

    for (std::size_t i{idx}; i < size; i++) {
      if (i + 1 < size and arr[i] != target and arr[i + 1] != target) {
        continue;
      }
      if (arr[i] != target) {
        right++;
      }
    }

    std::cout << std::max(left, right) * 2 << "\n";
  }
}