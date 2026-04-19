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

#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>

constexpr std::size_t MAX_COLORS = 50;

void solve() {
  std::size_t arr_size{};
  std::size_t query_size{};
  std::cin >> arr_size >> query_size;

  std::array<std::size_t, MAX_COLORS + 1> color_map{};
  color_map.fill(arr_size + 1);
  for (std::size_t i{1}; i <= arr_size; i++) {
    std::uint16_t color{};
    std::cin >> color;
    if (color_map.at(color) == arr_size + 1) {
      color_map.at(color) = i;
    }
  }

  for (std::size_t i{0}; i < query_size; i++) {
    std::uint16_t color{};
    std::cin >> color;
    auto& pos = color_map.at(color);
    std::cout << pos << " ";

    for (auto &val : color_map) {
      if (val < pos) {
        val++;
      }
    }

    pos = 1;
  }
}