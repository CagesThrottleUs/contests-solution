/*
 *   MIT License
 *
 *   Copyright (c) 2026 CagesThrottleUs
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 */

#include <cstddef>
#include <iostream>
#include <vector>

void solve() {

  int test_cases{};
  std::cin >> test_cases;
  while (test_cases--) {
    std::size_t num_eles{};
    std::cin >> num_eles;
    std::vector<int> eles(num_eles);
    std::size_t max_idx{0};
    for (std::size_t i = 0; i < num_eles; i++) {
      std::cin >> eles[i];
      if (eles[i] > eles[max_idx]) {
        max_idx = i;
      }
    }
    std::cout << eles[max_idx];
    for (std::size_t i = 0; i < num_eles; i++) {
      if (i != max_idx) {
        std::cout << " " << eles[i];
      }
    }
    std::cout << "\n";
  }
}