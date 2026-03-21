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

#include <cstddef>
#include <iostream>
#include <vector>
void solve() {
  std::size_t mat_size{};
  std::cin >> mat_size;

  std::vector<std::vector<int>> mat(mat_size + 1,
                                    std::vector<int>(mat_size + 1));

  for (std::size_t i{1}; i < mat_size; i++) {
    for (std::size_t j{i + 1}; j <= mat_size; j++) {
      std::cin >> mat[i][j];
    }
  }

  bool found{false};

  for (std::size_t first{1}; first < mat_size; first++) {
    for (std::size_t third{first + 2}; third <= mat_size; third++) {
      for (std::size_t second{first + 1}; second < third; second++) {
        if (mat[first][second] + mat[second][third] < mat[first][third]) {
          found = true;
          break;
        }
      }
    }
  }

  if (found) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}
