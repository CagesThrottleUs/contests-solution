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
#include <functional>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

constexpr int MAX_POW{30};
constexpr int MAX_POSITION{1'000'000'000};
constexpr std::size_t BASE{10};

    inline auto
    build_map() -> std::unordered_set<std::size_t> {
  std::size_t num{1};
  std::unordered_set<std::size_t> pow_2_map;
  pow_2_map.reserve(MAX_POW + 1);
  for (int i{0}; i <= MAX_POW; i++) {
    pow_2_map.insert(num);
    num *= 2;
  }
  return pow_2_map;
}

inline auto find_power_10(std::size_t num) -> std::size_t {
  std::size_t num_digits{1};
  while (num > 0) {
    num /= BASE;
    num_digits *= BASE;
  }
  return num_digits;
}

void solve() {
  int position{};
  std::cin >> position;

  auto pow_2_map = build_map();

  std::priority_queue<std::size_t, std::vector<std::size_t>, std::greater<>>
      min_heap;

  std::unordered_set<std::size_t> visited;

  for (const auto& pow : pow_2_map) {
    min_heap.push(pow);
    visited.insert(pow);
  }

  std::size_t ans = 0;

  while ((position--) > 0) {
    auto curr_pow = min_heap.top();
    min_heap.pop();
    ans = curr_pow;

    for (const auto& pow : pow_2_map) {
      auto new_pow = (curr_pow * find_power_10(pow)) + pow;
      if (new_pow <= MAX_POSITION && !visited.contains(new_pow)) {
        visited.insert(new_pow);
        min_heap.push(new_pow);
      }
    }
  }

  std::cout << ans << "\n";
}