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
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
void solve() {
  std::int32_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    std::cin >> size;

    std::string first{};
    first.reserve(size);
    std::string second{};
    second.reserve(size);
    std::cin >> first >> second;

    std::vector<std::size_t> _dp(size + 1, 0);
    _dp[1] = (first[0] != second[0]) ? 1 : 0;

    for (std::size_t i{2}; i <= size; i++) {
      auto cost_vertical = (first[i - 1] != second[i - 1]) ? 1UZ : 0UZ;
      auto res = _dp[i - 1] + cost_vertical;

      auto cost_horizontal = ((first[i - 1] != first[i - 2]) ? 1UZ : 0UZ) +
                             ((second[i - 1] != second[i - 2]) ? 1UZ : 0UZ);

      _dp[i] = std::min(res, _dp[i - 2] + cost_horizontal);
    }

    std::cout << _dp[size] << "\n";
  }
}