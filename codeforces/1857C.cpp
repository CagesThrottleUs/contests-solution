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
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

constexpr std::int32_t SENTINEL = 1000000001;

void solve() {
  std::int32_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t original_size{};
    std::cin >> original_size;

    auto pair_wise_size = original_size * (original_size - 1) / 2;

    std::vector<std::int32_t> pairwise;
    pairwise.reserve(pair_wise_size);

    for (std::size_t i{0}; i < pair_wise_size; i++) {
      std::int32_t num{};
      std::cin >> num;
      pairwise.push_back(num);
    }

    std::ranges::sort(pairwise);

    std::vector<std::int32_t> original(original_size, SENTINEL);

    auto MAX_VAL = pairwise.back();

    std::size_t idx{0};

    for (std::size_t i{0}; i < original_size; i++) {
      original[i] = pairwise[idx];
      auto size = original_size - i - 1;
      auto prev_idx = idx;
      idx = prev_idx + size;
      if (idx >= pairwise.size()) {
        break;
      }
    }

    std::ranges::for_each(original, [&](std::int32_t num) -> std::int32_t {
      if (num == SENTINEL) {
        num = MAX_VAL;
      }
      std::cout << num << " ";
      return num;
    });

    std::cout << "\n";
  }
}