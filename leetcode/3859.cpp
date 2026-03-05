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

// Count subarrays with exactly k distinct integers, each appearing >= m times.
// For each left index we find the range of right indices [firstValidRight,
// lastValidRight] using two pointers: extend until we have k distinct
// (lastValidRight), and until we also have each distinct with freq >= m
// (firstValidRight).
class Solution {
  static constexpr int MAX_NUMS_LEN = 100000;

public:
  long long countSubarrays(std::vector<int> &nums, int k, int m) {
    const int n = static_cast<int>(nums.size());
    std::vector<int> freqToLimit(1 + MAX_NUMS_LEN, 0);
    std::vector<int> freqToValid(1 + MAX_NUMS_LEN, 0);

    int distinctToLimit = 0;
    int distinctToValid = 0;
    int distinctWithMinFreq = 0; // count of distinct values with freq >= m

    int rightLimit = 0; // [left, rightLimit - 1] has at most k distinct
    int rightValid = 0; // [left, rightValid - 1] is first window that is valid

    long long totalCount = 0;

    for (int left = 0; left < n; ++left) {
      // Extend rightLimit until adding one more would exceed k distinct
      while (rightLimit < n) {
        int x = nums[rightLimit];
        if (freqToLimit[x] == 0) {
          if (distinctToLimit == k)
            break;
          ++distinctToLimit;
        }
        ++freqToLimit[x];
        ++rightLimit;
      }

      // Extend rightValid until we have k distinct and each appears >= m times
      while (rightValid < n) {
        if (distinctToValid < k ||
            (distinctToValid == k && distinctWithMinFreq < k)) {
          int x = nums[rightValid];
          if (freqToValid[x] == 0) {
            if (distinctToValid == k)
              break;
            ++distinctToValid;
          }
          ++freqToValid[x];
          if (freqToValid[x] == m)
            ++distinctWithMinFreq;
          ++rightValid;
        } else {
          break;
        }
      }

      // Valid right indices for this left: [rightValid - 1, rightLimit - 1]
      if (distinctToValid == k && distinctWithMinFreq == k &&
          rightValid <= rightLimit) {
        totalCount += (rightLimit - rightValid + 1);
      }

      // Shrink: remove nums[left] from both windows
      int v = nums[left];
      --freqToLimit[v];
      if (freqToLimit[v] == 0)
        --distinctToLimit;

      if (freqToValid[v] == m)
        --distinctWithMinFreq;
      --freqToValid[v];
      if (freqToValid[v] == 0)
        --distinctToValid;
    }

    return totalCount;
  }
};
