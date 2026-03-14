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
#include <array>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

constexpr std::size_t NUM_CHARS{26};

void solve() {
  std::size_t str_len{};
  int left{};
  int right{};

  std::cin >> str_len >> left >> right;

  std::string str;
  str.reserve(str_len);
  std::cin >> str;

  std::size_t num_pairs{0};

  // auto print_arr = [](const std::vector<int>& arr) -> void {
  //   std::cout << "[" << arr.front();
  //   for (std::size_t i{1}; i < arr.size(); i++) {
  //     std::cout << ", " << arr[i];
  //   }
  //   std::cout << "]\n";
  // };

  std::array<std::vector<int>, NUM_CHARS> char_idx_map{};
  for (int j{0}; static_cast<std::size_t>(j) < str_len; j++) {
    auto _ch = static_cast<std::size_t>(str[static_cast<std::size_t>(j)] - 'a');
    char_idx_map.at(_ch).push_back(j);

    auto min_value = j - right;
    auto max_value = j - left;

    // std::cout << "min_value: " << min_value << ", max_value: " << max_value
    //           << "\n";
    // std::cout << "char_idx_map.at(_ch): ";
    // print_arr(char_idx_map.at(_ch));

    auto lower_itr = std::lower_bound(char_idx_map.at(_ch).begin(),
                                      char_idx_map.at(_ch).end(), min_value);
    auto upper_itr = std::upper_bound(char_idx_map.at(_ch).begin(),
                                      char_idx_map.at(_ch).end(), max_value);

    // std::cout << "lower_itr: "
    //           << std::distance(char_idx_map.at(_ch).begin(), lower_itr)
    //           << ", upper_itr: "
    //           << std::distance(char_idx_map.at(_ch).begin(), upper_itr) << "\n";

    num_pairs += static_cast<std::size_t>(std::distance(lower_itr, upper_itr));

    // std::cout << "num_pairs: " << num_pairs << "\n";
  }

  std::cout << num_pairs << "\n";
}