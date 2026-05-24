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
#include <cstdint>
#include <iostream>
#include <limits>
#include <string>
#include <string_view>
#include <vector>

inline auto find_cost(std::string_view str) -> std::size_t {
  const auto len = str.size();
  std::vector<std::size_t> answer(len + 1,
                                  std::numeric_limits<std::size_t>::max());

  for (std::size_t k = 1; k <= len; ++k) {
    for (std::size_t pos = k; pos <= len; pos += k) {
      if (str[pos - 1] == '1') {
        break;
      }
      answer[pos] = std::min(answer[pos], k);
    }
  }

  std::size_t cost = 0;
  for (std::size_t pos = 1; pos <= len; ++pos) {
    if (str[pos - 1] == '0') {
      cost += answer[pos];
    }
  }
  return cost;
}

void solve() {
  std::int32_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    std::cin >> size;

    std::string str;
    str.reserve(size);
    std::cin >> str;

    std::cout << find_cost(str) << "\n";
  }
}
