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

#ifdef __GNUC__
#ifndef __clang__
#pragma GCC optimize("O3", "unroll-loops")
#endif
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

#include <iostream>
#include <set>

auto get_primes(int num) -> std::set<int> {
  std::set<int> factors;

  // Handle 2 separately to allow for incrementing by 2 in the loop
  while (num % 2 == 0) {
    factors.insert(2);
    num /= 2;
  }

  // Check odd numbers from 3 up to sqrt(n)
  for (int i = 3; i * i <= num; i += 2) {
    while (num % i == 0) {
      factors.insert(i);
      num /= i;
    }
  }

  // If n is still > 1, the remaining n must be prime
  if (num > 1) {
    factors.insert(num);
  }

  return factors;
}

auto multiply_primes(const std::set<int> &primes) -> int {
  int result = 1;
  for (int prime : primes) {
    result *= prime;
  }
  return result;
}

void solve() {
  int num_test_cases{};
  std::cin >> num_test_cases;
  while (num_test_cases--) {
    int num;
    std::cin >> num;
    auto primes = get_primes(num);
    auto product = multiply_primes(primes);
    std::cout << product << "\n";
  }
}
