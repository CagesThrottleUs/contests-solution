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
#include <ostream>
#include <vector>

void print(const std::vector<std::size_t>& arr) {
  if (arr.empty()) {
    return;
  }
  std::cout << arr.front();
  for (std::size_t i{1}; i < arr.size(); i++) {
    std::cout << " " << arr[i];
  }
  std::cout << "\n";
}

void solve() {
  int tests{};
  std::cin >> tests;

  // std::cout << "DEBUG: TESTS: " << tests << std::endl;

  while ((tests--) != 0) {
    std::size_t total_shoes{};
    std::cin >> total_shoes;

    // std::cout << "DEBUG: TOTAL SHOES: " << total_shoes << "\n";

    std::vector<std::size_t> shoe_permutation(total_shoes);

    for (std::size_t i{0}; i < total_shoes; i++) {
      shoe_permutation[i] = i + 1;
    }

    std::size_t left{1};
    int invariant{0};

    bool panic{false};

    for (std::size_t i{1}; i <= total_shoes; i++) {
      int curr{};
      std::cin >> curr;
      // std::cout << "DEBUG: CURR: " << curr << "\n";
      if (panic) {
        continue;
      }
      if (i == left) {
        // std::cout << "DEBUG: I == LEFT\n";
        invariant = curr;
        continue;
      }
      if (invariant != curr) {
        // std::cout << "DEBUG: INVARIANT != CURR\n";
        if ((i - left) == 1) {
          // std::cout << "DEBUG: (I - LEFT) == 1\n";
          panic = true;
        }
        std::reverse(
            shoe_permutation.begin() + static_cast<std::ptrdiff_t>(left - 1),
            shoe_permutation.begin() + static_cast<std::ptrdiff_t>(i - 1));
        std::reverse(
            shoe_permutation.begin() + static_cast<std::ptrdiff_t>(left),
            shoe_permutation.begin() + static_cast<std::ptrdiff_t>(i - 1));
        left = i;
        invariant = curr;
      }
    }

    if (panic || (total_shoes + 1 - left) == 1) {
      // std::cout << "DEBUG: PANIC OR (TOTAL SHOES + 1 - LEFT) == 1\n";
      std::cout << "-1\n";
      continue;
    }

    std::reverse(shoe_permutation.begin() + static_cast<std::ptrdiff_t>(left - 1),
                 shoe_permutation.end());
    std::reverse(
        shoe_permutation.begin() + static_cast<std::ptrdiff_t>(left),
        shoe_permutation.end());

    print(shoe_permutation);
  }
}
