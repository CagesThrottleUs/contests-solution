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

#include <bitset>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

constexpr std::size_t MAX_BITS = 31;

void solve() {
  int tests{};
  std::cin >> tests;
  while ((tests--) != 0) {
    std::size_t size_a{};
    std::size_t size_x{};
    std::cin >> size_a >> size_x;

    std::vector<std::uint32_t> arr_a;
    arr_a.reserve(size_a);
    for (std::size_t i{0}; i < size_a; i++) {
      std::uint32_t num{};
      std::cin >> num;
      arr_a.push_back(num);
    }

    std::vector<std::uint32_t> arr_x;
    arr_x.reserve(size_x);
    for (std::size_t i{0}; i < size_x; i++) {
      std::uint32_t num{};
      std::cin >> num;
      arr_x.push_back(num);
    }

    std::bitset<MAX_BITS> visited;

    for (const auto& q_pow : arr_x) {
      if (visited.test(q_pow)) {
        continue;
      }

      visited.set(q_pow);

      const auto pow_2 = (1U << q_pow);
      const auto and_mask = pow_2 - 1;
      const auto add_val = pow_2 >> 1U;

      for (auto& num : arr_a) {
        if ((num & and_mask) == 0) {
          num += add_val;
        }
      }
    }

    std::cout << arr_a.front();
    for (std::size_t i{1}; i < size_a; i++) {
      std::cout << " " << arr_a[i];
    }
    std::cout << "\n";
  }
}