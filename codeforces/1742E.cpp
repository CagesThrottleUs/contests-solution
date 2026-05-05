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
#include <cstdint>
#include <iostream>
#include <vector>

struct PrefixInfo {
  std::uint32_t max_val;
  std::uint64_t sum;
};

inline auto upper_bound(const std::vector<PrefixInfo>& prefix_info, std::uint32_t question) -> std::size_t {
  std::size_t count{prefix_info.size()};
  std::size_t step{0};

  std::size_t idx{0};

  while (count > 0) {
    auto itr = idx;
    step = count / 2;
    itr += step;

    if (question >= prefix_info[itr].max_val) {
      idx = itr + 1;
      count -= step + 1;
    } else {
      count = step;
    }
  }

  return idx;
}

void solve() {
  std::int16_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t num_steps{};
    std::size_t num_questions{};
    std::cin >> num_steps >> num_questions;

    std::vector<PrefixInfo> prefix_info;
    prefix_info.reserve(num_steps);

    std::uint32_t max_val{0};
    std::uint64_t sum{0};

    for (std::size_t i{0}; i < num_steps; i++) {
      std::uint32_t val{};
      std::cin >> val;
      max_val = std::max(max_val, val);
      sum += val;
      prefix_info.emplace_back(max_val, sum);
    }

    for (std::size_t i{0}; i < num_questions; i++) {
      std::uint32_t question{};
      std::cin >> question;

      auto idx = upper_bound(prefix_info, question);

      std::cout << (idx > 0 ? prefix_info[idx - 1].sum : 0) << " ";
    }
    std::cout << "\n";
  }
}