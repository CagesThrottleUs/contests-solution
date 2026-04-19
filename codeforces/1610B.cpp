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
#include <vector>

auto is_palindrome(const std::vector<std::uint32_t>& arr, std::uint32_t to_skip)
    -> bool {
  std::size_t left{0};
  std::size_t right{arr.size() - 1};

  while (left < right) {
    if (arr[left] == to_skip) {
      left++;
    } else if (arr[right] == to_skip) {
      right--;
    } else if (arr[left] != arr[right]) {
      return false;
    } else {
      left++;
      right--;
    }
  }
  return true;
}

void solve() {
  std::int32_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    std::cin >> size;

    std::vector<std::uint32_t> arr;
    arr.reserve(size);

    for (std::size_t i{0}; i < size; i++) {
      std::uint32_t num{};
      std::cin >> num;
      arr.emplace_back(num);
    }

    std::size_t left{0};
    std::size_t right{size - 1};

    while (left < right and arr[left] == arr[right]) {
      left++;
      right--;
    }

    if (left >= right) {
      std::cout << "YES\n";
      continue;
    }

    if (is_palindrome(arr, arr[left]) || is_palindrome(arr, arr[right])) {
      std::cout << "YES\n";
      continue;
    }

    std::cout << "NO\n";
  }
}