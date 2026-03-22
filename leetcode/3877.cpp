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
#include <unordered_map>
#include <vector>

class Solution {
  void update_first_half(int ele_cnt, std::vector<int>& nums, int index,
                         std::unordered_map<int, int>& xor_to_ele_cnt,
                         int xor_val) {
    if (index >= (static_cast<int>(nums.size()) / 2)) {
      return;
    }

    update_first_half(ele_cnt, nums, index + 1, xor_to_ele_cnt, xor_val);

    ele_cnt++;
    // NOLINTNEXTLINE(hicpp-signed-bitwise)
    xor_val ^= nums[static_cast<std::size_t>(index)];
    xor_to_ele_cnt[xor_val] = std::max(xor_to_ele_cnt[xor_val], ele_cnt);
    update_first_half(ele_cnt, nums, index + 1, xor_to_ele_cnt, xor_val);
  }

  void update_second_half(std::vector<int>& nums, int index,
                          std::unordered_map<int, int>& xor_to_ele_cnt,
                          int target, int& max_kept, int xor_val, int ele_cnt) {
    if (index >= static_cast<int>(nums.size())) {
      return;
    }

    update_second_half(nums, index + 1, xor_to_ele_cnt, target, max_kept,
                       xor_val, ele_cnt);

    ele_cnt++;
    // NOLINTNEXTLINE(hicpp-signed-bitwise)
    xor_val ^= nums[static_cast<std::size_t>(index)];
    // NOLINTNEXTLINE(hicpp-signed-bitwise)
    if (xor_to_ele_cnt.contains(target ^ xor_val)) {
      // NOLINTNEXTLINE(hicpp-signed-bitwise)
      max_kept = std::max(max_kept, xor_to_ele_cnt[target ^ xor_val] + ele_cnt);
    }
    update_second_half(nums, index + 1, xor_to_ele_cnt, target, max_kept,
                       xor_val, ele_cnt);
  }

 public:
  auto minRemovals(std::vector<int>& nums, int target) -> int {
    std::unordered_map<int, int> xor_to_ele_cnt;
    xor_to_ele_cnt[0] = 0;
    update_first_half(0, nums, 0, xor_to_ele_cnt, 0);

    // process second half (empty second half subset: xor=0, ele_cnt=0)
    int max_kept = xor_to_ele_cnt.contains(target) ? xor_to_ele_cnt[target] : -1;
    update_second_half(nums, static_cast<int>(nums.size()) / 2, xor_to_ele_cnt,
                       target, max_kept, 0, 0);

    if (max_kept == -1) {
      return -1;
    }
    return static_cast<int>(nums.size()) - max_kept;
  }
};