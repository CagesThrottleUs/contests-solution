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

#include <cstddef>
#include <queue>
#include <utility>
#include <vector>

class Solution {
  using Grid = std::vector<std::vector<char>>;

  std::vector<std::pair<std::int32_t, std::int32_t>> directions;

 public:
  Solution() : directions({{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {}

  auto numIslands(Grid& grid) -> std::int32_t {
    std::int32_t islands{0};
    for (std::size_t i{0}; i < grid.size(); i++) {
      for (std::size_t j{0}; j < grid[i].size(); j++) {
        if (grid[i][j] == '1') {
          islands++;
          bfs(grid, static_cast<std::int32_t>(i), static_cast<std::int32_t>(j));
        }
      }
    }
    return islands;
  }

 private:
  void bfs(Grid& grid, std::int32_t start_x, std::int32_t start_y) {
    std::queue<std::pair<std::int32_t, std::int32_t>> resolver;
    resolver.emplace(start_x, start_y);
    grid[static_cast<std::size_t>(start_x)][static_cast<std::size_t>(start_y)] =
        '0';

    while (!resolver.empty()) {
      auto [pos_x, pos_y] = resolver.front();
      resolver.pop();

      for (const auto& [_dx, _dy] : directions) {
        std::int32_t new_x = pos_x + _dx;
        std::int32_t new_y = pos_y + _dy;

        if (new_x < 0 or new_x >= static_cast<std::int32_t>(grid.size()) or
            new_y < 0 or new_y >= static_cast<std::int32_t>(grid[0].size()) or
            grid[static_cast<std::size_t>(new_x)]
                [static_cast<std::size_t>(new_y)] != '1') {
          continue;
        }

        resolver.emplace(new_x, new_y);
        grid[static_cast<std::size_t>(new_x)][static_cast<std::size_t>(new_y)] =
            '0';
      }
    }
  }
};