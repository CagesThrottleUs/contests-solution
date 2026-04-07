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

#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>

inline auto get_arr(std::size_t size) -> std::vector<int> {
  std::vector<int> arr;
  arr.reserve(size);
  for (std::size_t i{0}; i < size; i++) {
    int num{};
    std::cin >> num;
    arr.push_back(num);
  }
  return arr;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    std::cin >> size;

    auto arr_a = get_arr(size);

    auto a_prime = get_arr(size);

    std::size_t left{0};
    while (left < size) {
      if (arr_a[left] == a_prime[left]) {
        left++;
      } else {
        break;
      }
    }

    assert(left < size);

    std::size_t right{left};
    while (right < size) {
      if (right + 1 < size and a_prime[right] <= a_prime[right + 1]) {
        right++;
      } else {
        break;
      }
    }

    while (left < size) {
      if (left - 1 < size and a_prime[left - 1] <= a_prime[left]) {
        left--;
      } else {
        break;
      }
    }

    std::cout << left + 1 << " " << right + 1 << "\n";
  }
}