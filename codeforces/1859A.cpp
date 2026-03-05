/*
 *   MIT License
 *
 *   Copyright (c) 2026 CagesThrottleUs
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 */

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

auto can_divide(const std::vector<int> &arr) -> bool {
  auto [first, last] = std::equal_range(arr.begin(), arr.end(), arr.front());
  return last != arr.end();
}

auto get_b_and_c(const std::vector<int> &arr)
    -> std::pair<std::vector<int>, std::vector<int>> {
  auto [first, last] = std::equal_range(arr.begin(), arr.end(), arr.back());
  auto c = std::vector<int>(first, last);
  auto b = std::vector<int>(arr.begin(), first);
  return {b, c};
}

void print(const std::vector<int> &arr) {
  if (arr.empty()) {
    return;
  }
  std::cout << arr.front();
  for (int i = 1; i < arr.size(); i++) {
    std::cout << " " << arr[i];
  }
  std::cout << "\n";
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    int n{};
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());

    if (!can_divide(arr)) {
      std::cout << -1 << "\n";
    } else {
      auto [b, c] = get_b_and_c(arr);
      std::cout << b.size() << " " << c.size() << "\n";
      print(b);
      print(c);
    }
  }
}