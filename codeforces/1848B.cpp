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
#include <limits>
#include <unordered_map>
#include <vector>

inline auto process_planks(std::size_t planks)
    -> std::unordered_map<std::size_t, std::vector<std::size_t>> {
  std::unordered_map<std::size_t, std::vector<std::size_t>> result;
  std::unordered_map<std::size_t, std::size_t> last_known_pos;

  for (std::size_t i{0}; i < planks; i++) {
    std::size_t color{};
    std::cin >> color;
    if (!result.contains(color)) {
      result[color].push_back(i);
      last_known_pos[color] = i + 1;
      continue;
    }
    auto prev_pos = last_known_pos[color];
    result[color].push_back(i + 1 - prev_pos - 1);
    last_known_pos[color] = i + 1;
  }

  for (auto& [color, positions] : result) {
    positions.push_back(planks - last_known_pos[color]);
    auto max_itr = std::ranges::max_element(positions);
    auto val = *max_itr;
    if (val == 0) {
      continue;
    }
    auto half = (val - 1) / 2;
    auto first = half;
    auto second = (val - 1) - half;
    *max_itr = first;
    positions.push_back(second);
  }

  return result;
}

void solve() {
  std::int32_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t planks{};
    std::size_t colors{};
    std::cin >> planks >> colors;

    auto planks_map = process_planks(planks);

    std::size_t ans{std::numeric_limits<std::size_t>::max()};

    for (const auto& [color, positions] : planks_map) {
      ans = std::min(ans, *std::ranges::max_element(positions));
    }

    std::cout << ans << "\n";
  }
}