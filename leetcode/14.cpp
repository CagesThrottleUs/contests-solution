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

#include <string>
#include <vector>

class Solution {
 private:
  static auto intersect(const std::string& str, std::string& collected)
      -> void {
    std::size_t common{0};
    for (std::size_t i{0}; i < str.size() && i < collected.size(); i++) {
      if (str[i] == collected[i]) {
        common++;
      } else {
        break;
      }
    }
    collected = collected.substr(0, common);
  }

 public:
  auto longestCommonPrefix(std::vector<std::string>& strs) -> std::string {
    std::string collected{strs.front()};
    for (std::size_t i{1}; i < strs.size(); i++) {
      intersect(strs[i], collected);
    }
    return collected;
  }
};