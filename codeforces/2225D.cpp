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
#include <iostream>

constexpr std::uint64_t MOD = 998244353;

auto count_rems(std::uint64_t range, std::uint64_t rem) -> std::uint64_t {
  if (range < rem) {
    return 0;
  }

  return ((range - rem) / 4) + 1;
}

void solve() {
  std::int32_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::uint64_t range{};
    std::uint64_t to_include{};
    std::cin >> range >> to_include;

    auto a_0 = (count_rems(to_include - 1, 3) + 1) % MOD;
    auto b_0 =
        (count_rems(range, 3) - count_rems(to_include - 1, 3) + MOD) % MOD;

    auto a_1 = (count_rems(to_include - 1, 1)) % MOD;
    auto b_1 =
        (count_rems(range, 1) - count_rems(to_include - 1, 1) + MOD) % MOD;

    auto ans = (((a_0 * b_0) % MOD) + ((a_1 * b_1) % MOD)) % MOD;

    std::cout << ans << "\n";
  }
}