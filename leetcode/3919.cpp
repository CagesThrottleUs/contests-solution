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
#include <vector>

struct QueryParam {
  std::size_t lhs_in;
  std::size_t rhs_out;
};

class Solution {
 private:  // METHODS
  auto clear(std::size_t size) {
    forward.clear();
    fwd.clear();
    backward.clear();
    bwd.clear();
    forward.reserve(size - 1);
    backward.reserve(size - 1);
  }

  auto preprocess(std::vector<int>& nums) -> void {
    clear(nums.size());

    std::vector<std::uint32_t> diffs;
    diffs.reserve(nums.size() - 1);

    for (std::size_t i = 1; i < nums.size(); i++) {
      diffs.push_back(static_cast<std::uint32_t>(nums[i] - nums[i - 1]));
    }

    for (std::size_t i = 0; i < nums.size(); i++) {
      if (i == 0) {
        forward.push_back(1);
        continue;
      }
      if (i == nums.size() - 1) {
        backward.push_back(1);
        continue;
      }

      auto lhs = diffs[i - 1];
      auto rhs = diffs[i];

      if (lhs <= rhs) {
        backward.push_back(1);
        forward.push_back(rhs);
      } else {
        backward.push_back(lhs);
        forward.push_back(1);
      }
    }
  }

  auto create_prefix_sums() -> void {
    fwd.reserve(forward.size());
    bwd.reserve(backward.size());

    std::uint32_t sum{0};
    for (std::uint32_t val : forward) {
      sum += val;
      fwd.push_back(sum);
    }

    sum = 0;
    for (std::uint32_t val : backward) {
      sum += val;
      bwd.push_back(sum);
    }
  }

  static auto query(const std::vector<std::uint32_t>& prefix_sums,
                    std::size_t lhs, std::size_t rhs) -> std::uint32_t {
    if (lhs == 0) {
      return prefix_sums[rhs];
    }
    return prefix_sums[rhs] - prefix_sums[lhs - 1];
  }

 public:  // METHODS
  auto minCost(std::vector<int>& nums, std::vector<std::vector<int>>& queries)
      -> std::vector<int> {
    preprocess(nums);
    create_prefix_sums();

    std::vector<std::int32_t> results;

    for (auto& query : queries) {
      auto first = query[0];
      auto last = query[1];

      if (first <= last) {
        auto lhs = static_cast<std::size_t>(first);
        auto rhs = static_cast<std::size_t>(last) - 1;
        if (rhs >= fwd.size()) {
          results.push_back(0);
          continue;
        }
        auto result = Solution::query(fwd, lhs, rhs);
        results.push_back(static_cast<std::int32_t>(result));
      } else {
        auto lhs = static_cast<std::size_t>(last);
        auto rhs = static_cast<std::size_t>(first) - 1;
        if (rhs >= bwd.size()) {
          results.push_back(0);
          continue;
        }
        auto result = Solution::query(bwd, lhs, rhs);

        results.push_back(static_cast<std::int32_t>(result));
      }
    }
    return results;
  }

 private:  // MEMBERS
  std::vector<std::uint32_t> forward;
  std::vector<std::uint32_t> backward;

  std::vector<std::uint32_t> fwd;
  std::vector<std::uint32_t> bwd;

 public:  // MEMBERS
};