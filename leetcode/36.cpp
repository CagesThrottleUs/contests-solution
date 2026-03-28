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

#include <array>
#include <bitset>
#include <cstddef>
#include <vector>

constexpr std::size_t NUM = 9;
constexpr std::size_t NUM_BITS = NUM + 1;

class Solution {
  using BitsetArray = std::array<std::bitset<NUM_BITS>, NUM>;

 public:
  static auto isValidSudoku(std::vector<std::vector<char>>& board) -> bool {
    BitsetArray rows{};
    BitsetArray cols{};
    BitsetArray boxes{};

    for (std::size_t i{0}; i < NUM; i++) {
      for (std::size_t j{0}; j < NUM; j++) {
        if (board.at(i).at(j) == '.') {
          continue;
        }
        auto digit = static_cast<std::size_t>(board.at(i).at(j) - '0');
        auto box = ((i / 3) * 3) + (j / 3);
        if (rows.at(i).test(digit) || cols.at(j).test(digit) ||
            boxes.at(box).test(digit)) {
          return false;
        }
        rows.at(i).set(digit);
        cols.at(j).set(digit);
        boxes.at(box).set(digit);
      }
    }
    return true;
  }
};