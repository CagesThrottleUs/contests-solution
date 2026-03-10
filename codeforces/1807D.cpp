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
#include <vector>

void solve() {

  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    std::size_t queries{};
    std::cin >> size >> queries;

    // Prefix parity: parity_prefix[i] = (sum of a[0..i-1]) mod 2
    std::vector<std::uint_fast8_t> parity_prefix;
    parity_prefix.reserve(size + 1);
    parity_prefix.push_back(0);

    for (std::size_t i{0}; i < size; i++) {
      std::uint64_t val{};
      std::cin >> val;
      parity_prefix.push_back(parity_prefix.back() ^
                              static_cast<std::uint_fast8_t>(val & 1ULL));
    }

    const std::uint_fast8_t total_parity = parity_prefix[size];

    for (std::size_t i{0}; i < queries; i++) {
      std::size_t left{};
      std::size_t right{};
      std::cin >> left >> right;

      std::uint64_t constant{};
      std::cin >> constant;

      // (total - range + len*constant) mod 2 = total_parity ^ range_parity ^ (len*constant mod 2)
      std::uint_fast8_t range_parity =
          parity_prefix[right] ^ parity_prefix[left - 1];
      std::uint_fast8_t updated_parity =
          static_cast<std::uint_fast8_t>((right - left + 1) & 1ULL) &
          static_cast<std::uint_fast8_t>(constant & 1ULL);
      auto const result = static_cast<std::uint_fast8_t>(
          static_cast<unsigned>(total_parity) ^
          static_cast<unsigned>(range_parity) ^
          static_cast<unsigned>(updated_parity));

      std::cout << (result != 0U ? "YES" : "NO") << '\n';
    }
  }
}