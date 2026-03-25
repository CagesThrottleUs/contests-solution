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
#include <array>
#include <cstdint>
#include <iostream>

constexpr int MAX_N{40000};

using Sieve = std::array<bool, MAX_N + 1>;

auto build_sieve() -> Sieve {
  Sieve is_prime{};
  is_prime.fill(true);
  is_prime[0] = false;
  is_prime[1] = false;
  for (int i = 2; i <= MAX_N; i++) {
    if (is_prime.at(static_cast<std::size_t>(i)) and i * i <= MAX_N) {
      for (int j = i * i; j <= MAX_N; j += i) {
        is_prime.at(static_cast<std::size_t>(j)) = false;
      }
    }
  }
  return is_prime;
}

auto find_prime(const Sieve& sieve, std::int64_t start_pos) -> std::int64_t {
  for (std::int64_t i = start_pos; i < static_cast<std::int64_t>(sieve.size());
       i++) {
    if (sieve.at(static_cast<std::size_t>(i))) {
      return i;
    }
  }
  return -1;
}

void solve() {
  auto sieve = build_sieve();

  int tests{};
  std::cin >> tests;
  while ((tests--) != 0) {
    std::int64_t diff{};
    std::cin >> diff;

    auto first_prime = find_prime(sieve, 1 + diff);
    auto second_prime = find_prime(sieve, first_prime + diff);

    auto second = std::min(first_prime * first_prime, second_prime);

    std::int64_t res = first_prime * second;

    std::cout << res << "\n";
  }
}