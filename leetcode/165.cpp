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

#include <cstdint>
#include <iterator>
#include <string>

constexpr std::int32_t BASE = 10;

class Solution {
  static auto extract_digit(const std::string& version,
                            std::string::iterator& itr) -> std::int32_t {
    std::int32_t num{0};
    while (itr != version.end() and *itr != '.') {
      num = (num * BASE) + (*itr - '0');
      std::advance(itr, 1);
    }
    return num;
  }

 public:
  // NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
  static auto compareVersion(std::string& version1, std::string& version2)
      -> std::int32_t {
    auto first_v1 = version1.begin();
    auto first_v2 = version2.begin();

    while (first_v1 != version1.end() or first_v2 != version2.end()) {
      auto num_v1 = extract_digit(version1, first_v1);
      auto num_v2 = extract_digit(version2, first_v2);

      if (num_v1 < num_v2) {
        return -1;
      }
      if (num_v1 > num_v2) {
        return 1;
      }
      if (first_v1 != version1.end()) {
        first_v1 = std::next(first_v1);
      }
      if (first_v2 != version2.end()) {
        first_v2 = std::next(first_v2);
      }
    }
    return 0;
  }
};