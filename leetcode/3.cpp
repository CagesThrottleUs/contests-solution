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
#include <cstddef>
#include <string>
#include <unordered_map>

class Solution {
 public:
  auto lengthOfLongestSubstring(std::string str) -> int {
    std::unordered_map<char, std::size_t> visited;
    std::size_t left{0};
    std::size_t right{0};

    std::size_t max_len{0};

    while (right < str.size()) {
      if (visited.contains(str[right])) {
        auto prev_idx = visited[str[right]];
        for (std::size_t i = left; i <= prev_idx; i++) {
          visited.erase(str[i]);
        }
        left = prev_idx + 1;
      }
      visited[str[right]] = right;
      max_len = std::max(max_len, right - left + 1);
      right++;
    }

    return static_cast<int>(max_len);
  }
};