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
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

auto get_run_len_arr(std::size_t arr_size)
    -> std::unordered_map<int, std::size_t> {
  std::unordered_map<int, std::size_t> run_len_arr;

  int last{};
  std::cin >> last;
  std::size_t len{1};

  for (std::size_t i{1}; i < arr_size; i++) {
    int num{};
    std::cin >> num;
    if (num == last) {
      len++;
    } else {
      run_len_arr[last] = std::max(run_len_arr[last], len);
      last = num;
      len = 1;
    }
  }
  run_len_arr[last] = std::max(run_len_arr[last], len);
  return run_len_arr;
}

void print(const std::vector<std::pair<int, std::size_t>>& arr) {
  if (arr.empty()) {
    return;
  }
  std::cout << arr.front().first << " " << arr.front().second << "\n";
  for (std::size_t i{1}; i < arr.size(); i++) {
    std::cout << " " << arr[i].first << " " << arr[i].second << "\n";
  }
  std::cout << "\n";
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    int arr_size{};
    std::cin >> arr_size;

    auto arr_a = get_run_len_arr(static_cast<std::size_t>(arr_size));
    // std::cout << "DEBUG: COLLECTED ARR A\n";
    // print(arr_a);
    auto arr_b = get_run_len_arr(static_cast<std::size_t>(arr_size));
    // std::cout << "DEBUG: COLLECTED ARR B\n";
    // print(arr_b);

    std::size_t max_len{0};
    for (const auto& [num, len] : arr_a) {
      max_len = std::max(max_len, len);
    }
    for (const auto& [num, len] : arr_b) {
      max_len = std::max(max_len, len);
    }
    for (const auto& [num, len] : arr_a) {
      if (arr_b.contains(num)) {
        max_len = std::max(max_len, len + arr_b[num]);
      }
    }
    std::cout << max_len << "\n";
  }
}