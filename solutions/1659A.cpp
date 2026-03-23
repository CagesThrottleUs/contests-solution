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

#include <cstdint>
#include <iostream>
#include <string>

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::uint32_t total_matches{};
    std::uint32_t n_red_won{};
    std::uint32_t n_blue_won{};
    std::cin >> total_matches >> n_red_won >> n_blue_won;

    auto amt = n_red_won / (n_blue_won + 1);
    auto rem = n_red_won - (amt * (n_blue_won + 1));

    std::string ans;
    ans.reserve(total_matches);

    while (n_blue_won > 0) {
      auto cur_amt = amt;
      if (rem > 0) {
        cur_amt++;
        rem--;
      }
      ans += std::string(cur_amt, 'R');
      ans += std::string(1, 'B');
      n_blue_won--;
      n_red_won -= cur_amt;
    }

    ans += std::string(n_red_won, 'R');

    std::cout << ans << "\n";
  }
}
