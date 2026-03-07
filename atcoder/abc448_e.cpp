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

#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>

constexpr std::int64_t MOD{10007};
constexpr std::int64_t MAX_POW{31};
constexpr std::int64_t BASE{10};

auto binpow(std::int64_t base,  // NOLINT(bugprone-easily-swappable-parameters)
            std::int64_t pow,   // NOLINT(bugprone-easily-swappable-parameters)
            std::int64_t modulo) -> std::int64_t {
  base %= modulo;
  std::int64_t result = 1;
  while (pow > 0) {
    if ((pow & 1) == 1) {  // NOLINT(hicpp-signed-bitwise)
      result = result * base % modulo;
    }
    base = base * base % modulo;
    pow >>= 1;  // NOLINT(hicpp-signed-bitwise)
  }
  return result;
}

auto precompute_repunits(std::int64_t divisor)
    -> std::array<std::int64_t, MAX_POW> {
  std::array<std::int64_t, MAX_POW> repunits{};
  std::array<std::int64_t, MAX_POW> pow10{};  // pw10[i] = 10^(2^i) mod divisor

  pow10[0] = BASE % divisor;
  repunits[0] = 1;

  for (std::int64_t i = 1; i < MAX_POW; i++) {
    pow10.at(static_cast<std::size_t>(i)) =
        pow10.at(static_cast<std::size_t>(i - 1)) *
        pow10.at(static_cast<std::size_t>(i - 1)) % divisor;  // square previous
    repunits.at(static_cast<std::size_t>(i)) =
        repunits.at(static_cast<std::size_t>(i - 1)) *
        (pow10.at(static_cast<std::size_t>(i - 1)) + 1) % divisor;
  }
  return repunits;
}

auto calc_rem_for_repunit(std::int64_t repunit_len,
                          std::array<std::int64_t, MAX_POW>& repunits,
                          std::int64_t divisor) -> std::int64_t {
  // divide repunit_len into powers of 2
  std::int64_t num_till_now{0};
  std::int64_t curr_pow{0};
  std::int64_t result{0};
  while (repunit_len > 0) {
    if ((repunit_len & 1) == 1) {  // NOLINT(hicpp-signed-bitwise)
      result = (result + repunits.at(static_cast<std::size_t>(curr_pow)) *
                             binpow(BASE, num_till_now, divisor)) %
               divisor;
      num_till_now =
          num_till_now | (1 << curr_pow);  // NOLINT(hicpp-signed-bitwise)
    }
    curr_pow++;
    repunit_len >>= 1;  // NOLINT(hicpp-signed-bitwise)
  }
  return result;
}

void solve() {
  std::int64_t seq_len{};
  std::int64_t divisor{};
  std::cin >> seq_len >> divisor;

  auto repunits = precompute_repunits(MOD * divisor);

  std::int64_t remainder{0};
  for (std::int64_t i = 0; i < seq_len; i++) {
    std::int64_t digit{};
    std::int64_t cnt{};
    std::cin >> digit >> cnt;
    remainder = (remainder * binpow(BASE, cnt, MOD * divisor) +
                 digit * calc_rem_for_repunit(cnt, repunits, MOD * divisor)) %
                (MOD * divisor);
  }

  std::cout << remainder / divisor << "\n";
}