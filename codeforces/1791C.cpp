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
#include <iostream>
#include <string>

auto expected_ends(char start, char end) -> bool {
  return (start == '0' && end == '1') || (start == '1' && end == '0');
}

auto reduce_str(const std::string &str) -> std::size_t {
  std::size_t start{0};
  std::size_t end{str.size() - 1};

  while (start < end) {
    if (!expected_ends(str[start], str[end])) {
      break;
    }
    start++;
    end--;
  }

  if (start > end) {
    return 0;
  }

  return end - start + 1;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    int n{};
    std::cin >> n;
    std::string input{};
    input.reserve(static_cast<size_t>(n));
    std::cin >> input;
    auto sol = reduce_str(input);
    std::cout << sol << "\n";
  }
}