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
// #include <iostream>

constexpr std::int64_t MOD = 1'000'000'000 + 7;

class Solution {
 private:
  // NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
  static auto modpow(std::int64_t base, std::int64_t exp, std::int64_t mod)
      -> std::int64_t {
    std::int64_t result = 1;
    base %= mod;
    auto uexp = static_cast<std::uint64_t>(exp);
    while (uexp > 0ULL) {
      if ((uexp & 1ULL) == 1ULL) {
        result = result * base % mod;
      }
      base = base * base % mod;
      uexp >>= 1ULL;
    }
    return result;
  }

  // C(big, small) via the smaller side: O(min(rank, number-rank))
  // NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
  static auto nCr(std::int64_t number, std::int64_t rank) -> std::int64_t {
    if (rank < 0 or rank > number) {
      return 0;
    }
    rank = std::min(rank, number - rank);
    std::int64_t num = 1;
    std::int64_t den = 1;
    for (std::int64_t i = 1; i <= rank; i++) {
      num = num * ((number - rank + i) % MOD) % MOD;
      den = den * i % MOD;
    }
    return num * modpow(den, MOD - 2, MOD) % MOD;
  }

 public:
  // NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
  static auto countVisiblePeople(int total_ele, int /*pos*/, int total_cnt) -> int {
    return static_cast<int>(nCr(total_ele - 1, total_cnt) * 2 % MOD);
  }
};