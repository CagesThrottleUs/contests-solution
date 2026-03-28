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

#include <iostream>

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3", "unroll-loops")
#elif defined(__clang__)
#pragma clang optimize on
#endif

void speedup() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
}

// Forward declaration - to be implemented in problem file
void solve();

auto main() -> int {
  speedup();
  solve();
  return 0;
}

// Include the problem-specific implementation

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

using int64 = std::int64_t;
constexpr std::int32_t MOD = 1'000'000'007;
constexpr std::int32_t MAX_N = 100'005;
constexpr std::uint32_t BITS = 29U;

auto power(int64 base, std::uint64_t exponent) -> int64 {
  int64 res = 1;
  for (; exponent > 0U; exponent >>= 1U, base = (base * base) % MOD) {
    if ((exponent & 1U) != 0U) {
      res = (res * base) % MOD;
    }
  }
  return res;
}

struct Tables {
  std::vector<int64> fact;
  std::vector<int64> inv;
};

auto precompute() -> const Tables& {
  static const Tables tables = []() -> Tables {
    Tables tbl;
    tbl.fact.resize(static_cast<std::size_t>(MAX_N));
    tbl.inv.resize(static_cast<std::size_t>(MAX_N));
    tbl.fact[0] = 1;
    for (std::size_t i{1}; i < static_cast<std::size_t>(MAX_N); ++i) {
      tbl.fact[i] = (tbl.fact[i - 1] * static_cast<int64>(i)) % MOD;
    }
    const auto last = static_cast<std::size_t>(MAX_N - 1);
    tbl.inv[last] = power(tbl.fact[last], static_cast<std::uint64_t>(MOD - 2));
    for (std::int32_t i = MAX_N - 2; i >= 0; --i) {
      const auto idx = static_cast<std::size_t>(i);
      tbl.inv[idx] = (tbl.inv[idx + 1] * static_cast<int64>(i + 1)) % MOD;
    }
    return tbl;
  }();
  return tables;
}

auto nCr(std::int32_t number, std::int32_t rank) -> int64 {
  if (rank < 0 || rank > number) {
    return 0;
  }
  const auto& [fact, inv] = precompute();
  const auto num = static_cast<std::size_t>(number);
  const auto rnk = static_cast<std::size_t>(rank);
  return fact[num] * inv[rnk] % MOD * inv[num - rnk] % MOD;
}

void test_case() {
  std::int32_t b_size{};
  if (!(std::cin >> b_size)) {
    return;
  }

  std::vector<int64> b_arr(static_cast<std::size_t>(b_size) + 1);
  for (std::size_t i{1}; i <= static_cast<std::size_t>(b_size); ++i) {
    std::cin >> b_arr[i];
  }

  std::vector<std::int32_t> bit_src(BITS, 0);
  for (std::int32_t k = b_size; k >= 1; --k) {
    const auto mask = static_cast<std::uint64_t>(b_arr[static_cast<std::size_t>(k)]);
    for (std::uint32_t j = 0U; j < BITS; ++j) {
      if (((mask >> j) & 1ULL) != 0ULL) {
        bit_src[j] = k;
        const int64 val = static_cast<int64>(1ULL << j) % MOD;
        for (std::int32_t i = 1; i < k; ++i) {
          const int64 sub = (val * nCr(k, i)) % MOD;
          const auto idx = static_cast<std::size_t>(i);
          b_arr[idx] = (b_arr[idx] - sub + MOD) % MOD;
        }
      }
    }
  }

  for (std::int32_t i = 0; i < b_size; ++i) {
    std::uint32_t res = 0U;
    for (std::uint32_t j = 0U; j < BITS; ++j) {
      if (i < bit_src[j]) {
        res |= (1U << j);
      }
    }
    std::cout << res << (i == b_size - 1 ? "" : " ");
  }
  std::cout << "\n";
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    test_case();
  }
}
