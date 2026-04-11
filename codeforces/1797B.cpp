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
#include <cstdint>
#include <iostream>
#include <vector>

void get_grid(std::vector<std::vector<char>>& grid, std::size_t grid_size) {
  for (std::size_t i{0}; i < grid_size; i++) {
    std::vector<char> row;
    row.reserve(grid_size);
    for (std::size_t j{0}; j < grid_size; j++) {
      char cell{};
      std::cin >> cell;
      row.push_back(cell);
    }
    grid.push_back(row);
  }
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t grid_size{};
    std::int32_t num_ops{};
    std::cin >> grid_size >> num_ops;

    std::vector<std::vector<char>> grid;
    grid.reserve(grid_size);
    get_grid(grid, grid_size);

    std::int32_t ops{0};
    std::size_t count{0};
    const auto max_count = (grid_size * grid_size) / 2;
    // std::cout << "max_count: " << max_count << "\n";
    for (std::size_t i{0}; i < grid_size; i++) {
      for (std::size_t j{0}; j < grid_size; j++) {
        // std::cout << "Processing: " << i << ", " << j << "\n";
        if (grid[i][j] != grid[grid_size - i - 1][grid_size - j - 1]) {
          ops++;
        }
        count++;
        // std::cout << "count: " << count << "\n";
        // std::cout << "count >= max_count: " << (count >= max_count) << "\n";
        if (count >= max_count) {
          break;
        }
      }
      if (count >= max_count) {
        break;
      }
    }

    // std::cout << "ops: " << ops << "\n";
    // std::cout << "num_ops: " << num_ops << "\n";

    auto rem = num_ops - ops;

    // std::cout << "rem: " << rem << "\n";

    // NOLINTNEXTLINE(hicpp-signed-bitwise)
    if ((rem < 0) or ((rem & 1) == 1 and (grid_size & 1) == 0)) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
    }
  }
}