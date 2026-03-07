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
#include <utility>
#include <vector>

void print(const std::vector<int>& arr) {
  if (arr.empty()) {
    return;
  }
  std::cout << arr.front();
  for (std::size_t i{1}; i < arr.size(); i++) {
    std::cout << " " << arr[i];
  }
  std::cout << "\n";
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    int size{};
    std::cin >> size;

    std::vector<int> arr(static_cast<std::size_t>(size));
    std::int64_t sum = 0;
    bool is_beautiful = true;
    for (std::size_t i{0}; i < arr.size(); i++) {
      std::cin >> arr[i];
      if (sum == static_cast<std::int64_t>(arr[i])) {
        is_beautiful = false;
      }
      sum += arr[i];
    }

    if (is_beautiful) {
      std::cout << "YES\n";
      print(arr);
    } else if (arr.front() == arr.back()) {
      std::cout << "NO\n";
    } else {
      std::swap(arr.front(), arr.back());
      std::cout << "YES\n";
      print(arr);
    }
  }
}