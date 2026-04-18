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
#include <numeric>
#include <vector>

void solve() {
  std::int32_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    std::cin >> size;

    std::vector<std::uint64_t> arr(size);
    for (auto& val : arr) {
      std::cin >> val;
    }

    // gcd of elements at even indices (0, 2, 4, ...)
    std::uint64_t gcd_at_even{arr[0]};
    for (std::size_t i{2}; i < size; i += 2) {
      gcd_at_even = std::gcd(gcd_at_even, arr[i]);
    }

    // gcd of elements at odd indices (1, 3, 5, ...)
    std::uint64_t gcd_at_odd{arr[1]};
    for (std::size_t i{3}; i < size; i += 2) {
      gcd_at_odd = std::gcd(gcd_at_odd, arr[i]);
    }

    // Check if no element at the given start offset is divisible by d
    auto none_divisible = [&](std::uint64_t div, std::size_t start) -> bool {
      for (std::size_t i{start}; i < size; i += 2) {
        if (arr[i] % div == 0) {
          return false;
        }
      }
      return true;
    };

    // Case 1: even positions red (d = gcd_at_even), odd positions must not be
    // divisible
    if (none_divisible(gcd_at_even, 1UZ)) {
      std::cout << gcd_at_even << '\n';
      // Case 2: odd positions red (d = gcd_at_odd), even positions must not be
      // divisible
    } else if (none_divisible(gcd_at_odd, 0UZ)) {
      std::cout << gcd_at_odd << '\n';
    } else {
      std::cout << "0\n";
    }
  }
}
