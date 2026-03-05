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

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

auto work() -> int {
  int size{};
  std::cin >> size;

  std::unordered_map<int, int> last_idx;
  std::vector<int> dp(size, 0);

  for (int i = 0; i < size; i++) {
    int num{};
    std::cin >> num;
    if (last_idx.count(num) == 1) {
      dp[i] = std::max(dp[i], dp[last_idx[num]] + 1);
      last_idx.erase(num);
    } else {
      last_idx[num] = i;
    }
    if (i > 0) dp[i] = std::max(dp[i], dp[i - 1]);
  }
  return 2 * dp[size - 1];
}

void solve() {
  int num_test_cases{};
  std::cin >> num_test_cases;

  while (num_test_cases > 0) {
    num_test_cases--;
    auto sol = work();
    std::cout << sol << "\n";
  }
}
