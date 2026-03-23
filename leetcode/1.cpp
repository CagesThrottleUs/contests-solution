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
#include <unordered_map>
#include <vector>

class Solution {
 public:
  auto twoSum(std::vector<int>& nums, int target) -> std::vector<int> {
    std::unordered_map<std::int32_t, std::int32_t> num_to_idx;
    num_to_idx.reserve(nums.size());
    for (std::int32_t i{0}; i < static_cast<std::int32_t>(nums.size()); i++) {
      std::int32_t complement = target - nums[static_cast<std::size_t>(i)];
      auto itr = num_to_idx.find(complement);
      if (itr != num_to_idx.end()) {
        return {static_cast<int>(itr->second), static_cast<int>(i)};
      }
      num_to_idx[nums[static_cast<std::size_t>(i)]] = i;
    }
    return {};
  }
};