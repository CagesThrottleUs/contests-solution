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
#include <iostream>

inline auto reduce(std::uint64_t& num) -> std::uint64_t {
  std::uint64_t op_cnt{0};
  while ((num & 1ULL) == 0ULL) {
    num >>= 1ULL;
    op_cnt++;
  }
  return op_cnt;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::uint64_t start{};
    std::uint64_t target{};
    std::cin >> start >> target;

    auto to_reduce = (start > target) ? start : target;
    auto compare_against = (start > target) ? target : start;
    auto reduce_cnt = reduce(to_reduce);
    auto compare_reduce_cnt = reduce(compare_against);

    if ((to_reduce xor compare_against) != 0) {
      std::cout << -1 << "\n";
      continue;
    }

    auto op_cnt = (reduce_cnt > compare_reduce_cnt)
                      ? reduce_cnt - compare_reduce_cnt
                      : compare_reduce_cnt - reduce_cnt;

    std::cout << (op_cnt / 3) + static_cast<std::uint64_t>(op_cnt % 3 != 0)
              << "\n";
  }
}