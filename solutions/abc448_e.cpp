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

#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>

constexpr std::int64_t MOD{10007};
constexpr std::int64_t MAX_POW{31};
constexpr std::int64_t BASE{10};

struct Precomputed {
  std::array<std::int64_t, MAX_POW> repunits{};
  std::array<std::int64_t, MAX_POW> pow10{};  // pow10[i] = 10^(2^i) mod M
};

auto precompute(std::int64_t divisor) -> Precomputed {
  Precomputed out{};
  out.pow10[0] = BASE % divisor;
  out.repunits[0] = 1;
  for (std::size_t i = 1; i < static_cast<std::size_t>(MAX_POW); i++) {
    std::int64_t last_pow = out.pow10.at(i - 1);
    out.pow10.at(i) = last_pow * last_pow % divisor;
    out.repunits.at(i) =
        out.repunits.at(i - 1) * (out.pow10.at(i - 1) + 1) % divisor;
  }
  return out;
}

// Returns { 10^len mod M, repunit(len) mod M } in one pass over bits of len.
inline void power10_and_repunit(std::int64_t len,
                                const Precomputed& precomputes,
                                std::int64_t divisor, std::int64_t& out_pow10,
                                std::int64_t& out_repunit) {
  out_pow10 = 1;
  out_repunit = 0;
  for (std::size_t i = 0; len > 0;
       i++, len >>= 1) {   // NOLINT(hicpp-signed-bitwise)
    if ((len & 1) == 0) {  // NOLINT(hicpp-signed-bitwise)
      continue;
    }
    out_repunit =
        (out_repunit + precomputes.repunits.at(i) * out_pow10) % divisor;
    out_pow10 = out_pow10 * precomputes.pow10.at(i) % divisor;
  }
}

void solve() {
  std::int64_t seq_len{};
  std::int64_t divisor{};
  std::cin >> seq_len >> divisor;

  const std::int64_t big_divisors = MOD * divisor;
  auto precomputes = precompute(big_divisors);

  std::int64_t remainder{0};
  for (std::int64_t i = 0; i < seq_len; i++) {
    std::int64_t digit{};
    std::int64_t cnt{};
    std::cin >> digit >> cnt;
    std::int64_t pow10{};
    std::int64_t rep{};
    power10_and_repunit(cnt, precomputes, big_divisors, pow10, rep);
    remainder = (remainder * pow10 + digit * rep) % big_divisors;
  }

  std::cout << remainder / divisor << "\n";
}
