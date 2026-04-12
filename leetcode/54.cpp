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
#include <vector>

class Solution {
 public:
  static auto spiralOrder(std::vector<std::vector<int>>& matrix)
      -> std::vector<int> {
    auto cell = [&](int row, int col) -> int {
      return matrix[static_cast<std::size_t>(row)]
                   [static_cast<std::size_t>(col)];
    };

    std::vector<int> order;
    int top{0};
    int bottom{static_cast<int>(matrix.size()) - 1};
    int left{0};
    int right{static_cast<int>(matrix[0].size()) - 1};

    while (top <= bottom && left <= right) {
      for (int col{left}; col <= right; col++) {
        order.push_back(cell(top, col));
      }
      ++top;

      for (int row{top}; row <= bottom; row++) {
        order.push_back(cell(row, right));
      }
      --right;

      if (top <= bottom) {
        for (int col{right}; col >= left; col--) {
          order.push_back(cell(bottom, col));
        }
        --bottom;
      }

      if (left <= right) {
        for (int row{bottom}; row >= top; row--) {
          order.push_back(cell(row, left));
        }
        ++left;
      }
    }

    return order;
  }
};