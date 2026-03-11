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
#include <iostream>
#include <utility>

constexpr int LOWER_LIM{0};
constexpr int UPPER_LIM{101};

auto process_pairs(int size) -> std::pair<int, int> {
  std::pair<int, int> range{LOWER_LIM, UPPER_LIM};

  int first{};
  int second{};
  std::cin >> first >> second;

  range.first = first;
  range.second = second;

  for (int i{1}; i < size; i++) {
    std::cin >> first >> second;

    if (second < range.first) {
      range.first = second;
      range.second = second;
    } else if (first > range.second) {
      range.first = first;
      range.second = first;
    } else if (first <= range.first && second >= range.second) {
      // do nothing
    } else if (first >= range.first && first <= range.second) {
      range.first = first;
      range.second = std::min(range.second, second);
    } else if (second >= range.first && second <= range.second) {
      range.second = second;
      range.first = std::max(range.first, first);
    } else {
      std::cout << "Unhandled case\n";
    }
  }

  return range;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    int size{};
    std::cin >> size;

    auto range = process_pairs(size);

    std::cout << range.second << "\n";
  }
}