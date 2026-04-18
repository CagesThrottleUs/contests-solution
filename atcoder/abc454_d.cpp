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

#include <cstdint>
#include <iostream>
#include <string>

auto normalize(const std::string& str) -> std::string {
  std::string result{};

  for (const auto cur : str) {
    const auto len = result.size();
    if (cur == ')' && len >= 3UZ &&
        result[len - 1] == 'x' && result[len - 2] == 'x' && result[len - 3] == '(') {
      result.resize(len - 3);
      result += "xx";
    } else {
      result.push_back(cur);
    }
  }

  return result;
}

void solve() {
  std::int32_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::string first{};
    std::string second{};

    std::cin >> first >> second;

    auto norm_first = normalize(first);
    auto norm_second = normalize(second);

    if (norm_first.size() != norm_second.size()) {
      std::cout << "No\n";
      continue;
    }

    if (norm_first == norm_second) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
  }
}