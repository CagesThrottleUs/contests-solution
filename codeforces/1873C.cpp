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

#include <cstddef>
#include <iostream>

constexpr int GRID_SIZE = 10;

auto get_score(std::size_t i, std::size_t j) -> int {
  if (i >= GRID_SIZE / 2) {
    i = GRID_SIZE - i - 1;
  }
  int max_score = i + 1;

  if (j >= i && j <= GRID_SIZE - i - 1) {
    return max_score;
  } else {
    if (j < i) {
      return max_score + (j - i);
    } else {
      return max_score + (GRID_SIZE - i - 1 - j);
    }
  }
}

auto work() -> int {
  std::size_t i{0};
  std::size_t j{0};

  int score{0};

  for (i = 0; i < GRID_SIZE; i++) {
    for (j = 0; j < GRID_SIZE; j++) {
      char cell{};
      std::cin >> cell;
      if (cell == 'X') {
        auto idx_score = get_score(i, j);
        score += idx_score;
        // std::cout << "i: " << i << ", j: " << j << ", idx_score: " << idx_score
        //           << "\n";
        // std::cout << "score: " << score << "\n";
      }
    }
  }

  return score;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    auto score = work();
    std::cout << score << "\n";
  }
}