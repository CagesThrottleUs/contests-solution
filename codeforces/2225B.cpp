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
#include <string>
#include <utility>
#include <vector>

auto perform_operation(const std::string& input, std::string& alternating)
    -> bool {
  std::vector<std::pair<std::size_t, std::size_t>> diff_substr;

  for (std::size_t i{0}; i < input.size(); i++) {
    if (input[i] != alternating[i]) {
      auto start = i;

      while (i < input.size() and input[i] != alternating[i]) {
        i++;
      }

      i--;

      diff_substr.emplace_back(start, i);
    }
  }

  if (diff_substr.size() > 1) {
    return false;
  }

  if (diff_substr.empty()) {
    return true;
  }

  auto actual_input =
      input.substr(diff_substr.front().first,
                   diff_substr.front().second - diff_substr.front().first + 1);
  auto actual_alternating = alternating.substr(
      diff_substr.front().first,
      diff_substr.front().second - diff_substr.front().first + 1);

  std::ranges::reverse(actual_alternating);

  if (actual_alternating == actual_input) {
    return true;
  }

  std::size_t diff_cnt{0};

  for (std::size_t i{0}; i < actual_input.size(); i++) {
    if (actual_input[i] != actual_alternating[i]) {
      diff_cnt++;
    }
  }

  return diff_cnt == actual_input.size();
}

void solve() {
  std::int32_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::string input{};
    std::cin >> input;

    std::string alternating_1{};  // starts with a
    std::string alternating_2{};  // starts with b

    for (std::size_t i{0}; i < input.size(); i++) {
      if (i % 2 == 0) {
        alternating_1 += 'a';
        alternating_2 += 'b';
      } else {
        alternating_1 += 'b';
        alternating_2 += 'a';
      }
    }

    if (perform_operation(input, alternating_1) or
        perform_operation(input, alternating_2)) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}