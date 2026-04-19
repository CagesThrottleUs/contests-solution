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

#include <algorithm>
#include <array>
#include <cstddef>
#include <queue>
#include <utility>
#include <vector>

class Solution {
  static constexpr std::array<std::pair<int, int>, 4> DIRS = {
      {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

  struct Ctx {
    int rows;
    int cols;
    std::vector<std::vector<int>>& grid;       // NOLINT
    std::vector<int>& pending;                 // NOLINT
    std::vector<std::size_t>& touched;         // NOLINT
    std::queue<std::pair<int, int>>& frontier; // NOLINT
  };

  static void spread_from(int row, int col, Ctx& ctx) {
    const int my_color =
        ctx.grid[static_cast<std::size_t>(row)][static_cast<std::size_t>(col)];
    const auto col_sz = static_cast<std::size_t>(ctx.cols);
    for (auto [drow, dcol] : DIRS) {
      const int next_row = row + drow;
      const int next_col = col + dcol;
      if (next_row < 0 || next_row >= ctx.rows || next_col < 0 ||
          next_col >= ctx.cols) {
        continue;
      }
      const auto nri = static_cast<std::size_t>(next_row);
      const auto nci = static_cast<std::size_t>(next_col);
      if (ctx.grid[nri][nci] != 0) {
        continue;
      }
      const std::size_t idx = (nri * col_sz) + nci;
      if (ctx.pending[idx] == 0) {
        ctx.touched.push_back(idx);
      }
      ctx.pending[idx] = std::max(ctx.pending[idx], my_color);
    }
  }

  static void commit_level(Ctx& ctx) {
    const auto col_sz = static_cast<std::size_t>(ctx.cols);
    for (std::size_t idx : ctx.touched) {
      const std::size_t nri = idx / col_sz;
      const std::size_t nci = idx % col_sz;
      ctx.grid[nri][nci] = ctx.pending[idx];
      ctx.frontier.emplace(static_cast<int>(nri), static_cast<int>(nci));
      ctx.pending[idx] = 0;
    }
    ctx.touched.clear();
  }

 public:
  // NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
  static auto colorGrid(int rows, int cols,
                        std::vector<std::vector<int>>& sources)
      -> std::vector<std::vector<int>> {
    const auto row_sz = static_cast<std::size_t>(rows);
    const auto col_sz = static_cast<std::size_t>(cols);

    std::vector<std::vector<int>> grid(row_sz, std::vector<int>(col_sz, 0));
    std::queue<std::pair<int, int>> frontier;
    for (const auto& src : sources) {
      grid[static_cast<std::size_t>(src[0])]
          [static_cast<std::size_t>(src[1])] = src[2];
      frontier.emplace(src[0], src[1]);
    }

    std::vector<int> pending(row_sz * col_sz, 0);
    std::vector<std::size_t> touched;
    touched.reserve(row_sz * col_sz);

    Ctx ctx{.rows = rows,
            .cols = cols,
            .grid = grid,
            .pending = pending,
            .touched = touched,
            .frontier = frontier};

    while (!frontier.empty()) {
      const std::size_t level_sz = frontier.size();
      for (std::size_t i = 0; i < level_sz; ++i) {
        auto [row, col] = frontier.front();
        frontier.pop();
        spread_from(row, col, ctx);
      }
      commit_level(ctx);
    }

    return grid;
  }
};
