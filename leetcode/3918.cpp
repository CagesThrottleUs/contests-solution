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
#include <cstdint>

constexpr std::int32_t BASE = 10;

class Solution {
  static auto reverse(std::int32_t num) -> std::int32_t {
    std::int32_t reversed = 0;
    while (num > 0) {
      reversed = (reversed * BASE) + (num % BASE);
      num /= BASE;
    }
    return reversed;
  }

  static auto is_prime(std::int32_t num) -> bool {
    if (num <= 1) {
      return false;
    }
    for (std::int32_t i = 2; i * i <= num; i++) {
      if (num % i == 0) {
        return false;
      }
    }
    return true;
  }

 public:
  static auto sumOfPrimesInRange(std::int32_t num) -> std::int32_t {
    auto reversed = reverse(num);

    auto lower = std::min(num, reversed);
    auto upper = std::max(num, reversed);

    std::int32_t sum = 0;

    for (std::int32_t i = lower; i <= upper; i++) {
      if (is_prime(i)) {
        sum += i;
      }
    }
    return sum;
  }
};