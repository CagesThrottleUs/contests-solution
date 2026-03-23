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
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests-- != 0) {
    std::size_t len{};
    std::cin >> len;

    std::vector<std::int64_t> visits(len);
    for (auto& val : visits) {
      std::cin >> val;
    }

    // Sort indices by visit count descending — most-visited gets closest spot
    std::vector<std::size_t> order(len);
    std::iota(order.begin(), order.end(), 0UZ);
    std::ranges::sort(order, [&](std::size_t lhs, std::size_t rhs) -> bool {
      return visits[lhs] > visits[rhs];
    });

    // Assign positions 1, -1, 2, -2, … — rank rk has |position| = rk/2 + 1
    std::vector<std::int64_t> coords(len);
    std::int64_t total_cost{};
    for (std::size_t rk{}; rk < len; rk++) {
      std::int64_t dist{static_cast<std::int64_t>((rk / 2) + 1)};
      coords[order[rk]] = (rk % 2 == 0) ? dist : -dist;
      total_cost += visits[order[rk]] * dist;
    }

    std::cout << 2 * total_cost << "\n0";
    for (std::int64_t pos : coords) {
      std::cout << ' ' << pos;
    }
    std::cout << '\n';
  }
}