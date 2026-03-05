/*
 *   MIT License
 *
 *   Copyright (c) 2026 CagesThrottleUs
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 */

#include <iostream>

#ifdef __GNUC__
#ifndef __clang__
#pragma GCC optimize("O3", "unroll-loops")
#endif
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

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

struct CurrentResult {
  std::size_t count_a{0};
  char current_char{'\0'};
};

auto get_results(const std::string &str) -> std::vector<CurrentResult> {
  std::vector<CurrentResult> results;
  std::size_t cnt_a{0};
  for (const auto &ch : str) {
    if (ch == 'A') {
      cnt_a++;
    } else {
      results.push_back({cnt_a, ch});
      cnt_a = 0;
    }
  }
  results.push_back({cnt_a, '\0'});
  return results;
}

void solve() {
  std::string s, t;
  std::cin >> s >> t;

  auto s_results = get_results(s);
  auto t_results = get_results(t);

//   std::cout << "s size: " << s_results.size() << "\n";
//   std::cout << "t size: " << t_results.size() << "\n";

  if (s_results.size() != t_results.size()) {
    std::cout << -1 << "\n";
    return;
  }

  std::size_t min_op{0};

  for (std::size_t i{0}; i < s_results.size(); i++) {
    if (s_results[i].current_char != t_results[i].current_char) {
      std::cout << -1 << "\n";
      return;
    } else {
      min_op += (s_results[i].count_a > t_results[i].count_a)
                    ? (s_results[i].count_a - t_results[i].count_a)
                    : (t_results[i].count_a - s_results[i].count_a);
    }
  }
  std::cout << min_op << "\n";
}
