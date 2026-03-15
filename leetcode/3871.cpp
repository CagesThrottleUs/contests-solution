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
#include <string>

constexpr std::int64_t BASE = 10;
constexpr std::int64_t LEN_SEP = 3;

class Solution {
 public:
  auto countCommas(std::int64_t num) -> std::int64_t {
    auto max_digits = (std::to_string(num).size());

    std::int64_t total{0};
    std::int64_t first_num{1};
    std::int64_t last_num{BASE};

    for (std::size_t i{1}; i <= max_digits; i++) {
      auto contrib = (i - 1) / LEN_SEP;
      auto total_ele = last_num - first_num;
      first_num *= BASE;
      last_num = (i == max_digits - 1) ? num + 1 : last_num * BASE;

      total += static_cast<std::int64_t>(contrib) * total_ele;
    }

    return total;
  }
};