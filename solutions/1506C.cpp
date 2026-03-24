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

#include <iostream>

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3", "unroll-loops")
#elif defined(__clang__)
#pragma clang optimize on
#endif

void speedup() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
}

// Forward declaration - to be implemented in problem file
void solve();

auto main() -> int {
  speedup();
  solve();
  return 0;
}

// Include the problem-specific implementation

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

// Z-algorithm implementation
auto is_substring(const std::string& first, const std::string& second) -> bool {
  std::string combined = second + "$" + first;
  std::vector<std::size_t> z_arr(combined.size(), 0);
  std::size_t left{0};
  std::size_t right{0};
  for (std::size_t i{1}; i < combined.size(); i++) {
    if (i < right) {
      z_arr[i] = std::min(right - i, z_arr[i - left]);
    }
    while (z_arr[i] + i < combined.size() &&
           combined[z_arr[i]] == combined[z_arr[i] + i]) {
      z_arr[i]++;
    }
    if (z_arr[i] + i > right) {
      left = i;
      right = z_arr[i] + i;
    }
  }
  return std::ranges::any_of(
      z_arr, [len = second.size()](auto val) -> bool { return val == len; });
}

void solve() {
  int tests{};
  std::cin >> tests;

  // std::cout << "DEBUG: tests: " << tests << "\n";

  while ((tests--) != 0) {
    std::string first{};
    std::string second{};
    std::cin >> first >> second;

    // std::cout << "DEBUG: first: " << first << "\n";
    // std::cout << "DEBUG: second: " << second << "\n";

    if (first.length() < second.length()) {
      std::swap(first, second);
    }

    // std::cout << "DEBUG: first after swap: " << first << "\n";
    // std::cout << "DEBUG: second after swap: " << second << "\n";

    bool found = false;
    for (std::size_t len{second.size()}; len <= second.size(); len--) {
      for (std::size_t i{0}; len + i - 1 < second.size(); i++) {
        std::string second_substr = second.substr(i, len);
        // std::cout << "DEBUG: second_substr: " << second_substr << "\n";
        auto is_sub = is_substring(first, second_substr);
        // std::cout << "DEBUG: is_sub: " << is_sub << "\n";
        if (is_sub) {
          // std::cout << "DEBUG: len: " << len << "\n";
          // std::cout << "DEBUG: i: " << i << "\n";
          // std::cout << "DEBUG: second_substr: " << second_substr << "\n";
          // std::cout << "DEBUG: first: " << first << "\n";
          // std::cout << "DEBUG: second: " << second << "\n";
          std::cout << (first.length() + second.length()) - (len * 2) << "\n";
          found = true;
          break;
        }
      }
      if (found) {
        break;
      }
    }

    if (!found) {
      std::cout << first.length() + second.length() << "\n";
    }
  }
}
