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

inline auto compute_water(const int height, const std::vector<int>& heights)
    -> std::int64_t {
  std::int64_t water{0};
  std::ranges::for_each(heights, [&water, height](const auto& arr_h) -> auto {
    water += std::max(0, height - arr_h);
  });
  return water;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    std::cin >> size;

    int max_water{};
    std::cin >> max_water;

    std::vector<int> heights;
    heights.reserve(size);
    int max_height{0};
    for (std::size_t i{0}; i < size; i++) {
      int height{};
      std::cin >> height;
      max_height = std::max(max_height, height);
      heights.push_back(height);
    }

    int left{1};
    int right{max_height + max_water};

    while (left <= right) {
      int mid = left + ((right - left) / 2);
      auto water_consumed = compute_water(mid, heights);
      // std::cout << "MID: " << mid << ", WATER_CONSUMED: " << water_consumed
      //           << "\n";
      if (water_consumed <= max_water) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    std::cout << right << "\n";
  }
}