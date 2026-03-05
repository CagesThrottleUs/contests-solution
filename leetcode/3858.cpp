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

#include <vector>

class Solution {
public:
  int minimumOR(std::vector<std::vector<int>>& grid) {
    const int m = static_cast<int>(grid.size());
    int ans = 0;

    // 10^5 < 2^17: for each bit from high to low, try to keep it 0
    for (int k = 16; k >= 0; --k) {
      const int mask = ans | ((1 << k) - 1);  // allowed bits: ans and bits < k

      bool can_avoid = true;
      for (int i = 0; i < m; ++i) {
        bool row_ok = false;
        for (int val : grid[i]) {
          if ((val & ~mask) == 0) {  // val has no bit outside mask => bit k can stay 0
            row_ok = true;
            break;
          }
        }
        if (!row_ok) {
          can_avoid = false;
          break;
        }
      }

      if (!can_avoid)
        ans |= (1 << k);
    }

    return ans;
  }
};
