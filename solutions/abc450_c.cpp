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

#include <array>
#include <cstddef>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

constexpr std::array<std::pair<int, int>, 4> DIRS = {
    {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

auto touches_border(int row, int col, int height, int width) -> bool {
  return row == 0 || row == height - 1 || col == 0 || col == width - 1;
}

auto flood_fill(std::vector<std::vector<int>>& mat, int height, int width,
                std::pair<int, int> start) -> bool {
  bool on_border = false;
  std::queue<std::pair<int, int>> bfs;
  mat[static_cast<std::size_t>(start.first)]
     [static_cast<std::size_t>(start.second)] = 1;
  bfs.push(start);

  while (!bfs.empty()) {
    auto [row, col] = bfs.front();
    bfs.pop();

    on_border = on_border || touches_border(row, col, height, width);

    for (auto [drow, dcol] : DIRS) {
      int next_row = row + drow;
      int next_col = col + dcol;
      if (next_row >= 0 && next_row < height && next_col >= 0 &&
          next_col < width &&
          mat[static_cast<std::size_t>(next_row)]
             [static_cast<std::size_t>(next_col)] == 0) {
        mat[static_cast<std::size_t>(next_row)]
           [static_cast<std::size_t>(next_col)] = 1;
        bfs.emplace(next_row, next_col);
      }
    }
  }

  return on_border;
}

auto perform_bfs(std::vector<std::vector<int>>& mat) -> int {
  auto height = static_cast<int>(mat.size());
  auto width = static_cast<int>(mat[0].size());
  int total{0};

  for (int row{0}; row < height; row++) {
    for (int col{0}; col < width; col++) {
      if (mat[static_cast<std::size_t>(row)][static_cast<std::size_t>(col)] ==
          1) {
        continue;
      }
      if (!flood_fill(mat, height, width, {row, col})) {
        total++;
      }
    }
  }

  return total;
}

void solve() {
  std::size_t height{};
  std::size_t width{};
  std::cin >> height >> width;

  std::vector<std::vector<int>> mat(height, std::vector<int>(width));
  for (std::size_t i{0}; i < height; i++) {
    for (std::size_t j{0}; j < width; j++) {
      char cell{};
      std::cin >> cell;
      mat[i][j] = (cell == '#' ? 1 : 0);
    }
  }

  std::cout << perform_bfs(mat) << "\n";
}
