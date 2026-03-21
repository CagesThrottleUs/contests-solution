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

auto get_max_dist(const std::string& str, std::size_t str_len, char curr)
    -> void {
  std::size_t max_dist{0};
  std::size_t first_g_pos{str.find('g')};
  for (std::size_t i{0}; i < str_len; i++) {
    bool break_out{false};
    if (str[i] == curr) {
      auto dist = str.find('g', i);
      if (dist != std::string::npos) {
        auto next_idx = dist;
        dist = dist - i;
        i = next_idx;
      } else {
        dist = (str_len - i) + first_g_pos;
        break_out = true;
      }
      max_dist = std::max(max_dist, dist);
    }
    if (break_out) {
      break;
    }
  }
  std::cout << max_dist << "\n";
}

void solve() {
  int tests{};
  std::cin >> tests;
  while ((tests--) != 0) {
    std::size_t str_len{};
    char curr{};
    std::cin >> str_len >> curr;

    std::string str;
    str.reserve(str_len);
    std::cin >> str;

    if (curr == 'g') {
      std::cout << 0 << "\n";
      continue;
    }

    get_max_dist(str, str_len, curr);
  }
}
