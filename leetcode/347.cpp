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
#include <unordered_map>
#include <vector>

class Solution {
 public:
  auto topKFrequent(std::vector<int>& nums, int count) -> std::vector<int> {
    std::unordered_map<int, std::size_t> freq;
    for (const auto& num : nums) {
      freq[num]++;
    }

    auto cmp = [&freq](const int& lhs, const int& rhs) -> bool {
      return freq[lhs] < freq[rhs];
    };

    std::priority_queue<int, std::vector<int>, decltype(cmp)> _pq(cmp);
    for (const auto& [num, count] : freq) {
      _pq.push(num);
    }

    std::vector<int> result;

    while (count > 0 and !_pq.empty()) {
      result.push_back(_pq.top());
      _pq.pop();
      count--;
    }

    return result;
  }
};