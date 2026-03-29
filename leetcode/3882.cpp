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

#include <bitset>
#include <cstddef>
#include <vector>

class Solution {
  static constexpr std::size_t MAX_XOR{1024};

 public:
  static auto minCost(std::vector<std::vector<int>>& grid) -> int {
    const std::size_t rows{grid.size()};
    const std::size_t cols{grid[0].size()};

    std::vector<std::vector<std::bitset<MAX_XOR>>> reach(
        rows, std::vector<std::bitset<MAX_XOR>>(cols));

    reach[0][0].set(static_cast<std::size_t>(grid[0][0]));

    for (std::size_t i{1}; i < rows; ++i) {
      const auto val{static_cast<std::size_t>(grid[i][0])};
      // Each bit b in reach[i-1][0] contributes b^val to reach[i][0]
      for (std::size_t bit{0}; bit < MAX_XOR; ++bit) {
        if (reach[i - 1][0].test(bit)) {
          reach[i][0].set(bit ^ val);
        }
      }
    }
    for (std::size_t j{1}; j < cols; ++j) {
      const auto val{static_cast<std::size_t>(grid[0][j])};
      for (std::size_t bit{0}; bit < MAX_XOR; ++bit) {
        if (reach[0][j - 1].test(bit)) {
          reach[0][j].set(bit ^ val);
        }
      }
    }

    for (std::size_t i{1}; i < rows; ++i) {
      for (std::size_t j{1}; j < cols; ++j) {
        const auto val{static_cast<std::size_t>(grid[i][j])};
        const std::bitset<MAX_XOR> combined{reach[i - 1][j] | reach[i][j - 1]};
        for (std::size_t bit{0}; bit < MAX_XOR; ++bit) {
          if (combined.test(bit)) {
            reach[i][j].set(bit ^ val);
          }
        }
      }
    }

    for (std::size_t bit{0}; bit < MAX_XOR; ++bit) {
      if (reach[rows - 1][cols - 1].test(bit)) {
        return static_cast<int>(bit);
      }
    }
    return -1;
  }
};