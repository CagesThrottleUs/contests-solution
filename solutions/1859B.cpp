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

#include <iostream>

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3", "unroll-loops")
#elif defined(__clang__)
#pragma clang optimize on
#endif

void speedup() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
}

// Forward declaration - to be implemented in problem file
void solve();

auto main() -> int {
  speedup();
  solve();
  return 0;
}

// Include the problem-specific implementation

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

auto get_min_vals(std::size_t num_arrs) -> std::vector<std::pair<int, int>> {
  std::vector<std::pair<int, int>> min_vals;
  min_vals.reserve(num_arrs);

  for (std::size_t i = 0; i < num_arrs; i++) {
    int arr_size{};
    std::cin >> arr_size;
    int first_min{std::numeric_limits<int>::max()};
    int second_min{std::numeric_limits<int>::max()};

    for (int j = 0; j < arr_size; j++) {
      int val{};
      std::cin >> val;
      if (val < first_min) {
        second_min = first_min;
        first_min = val;
      } else if (val < second_min) {
        second_min = val;
      }
    }

    min_vals.emplace_back(first_min, second_min);
  }
  return min_vals;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t num_arrs{};
    std::cin >> num_arrs;

    auto min_vals = get_min_vals(num_arrs);

    std::size_t min_idx = 0;
    std::int64_t sum_second_mins{0};

    for (std::size_t i = 0; i < num_arrs; i++) {
      if (min_vals[i].first < min_vals[min_idx].first) {
        min_idx = i;
      }
      sum_second_mins += min_vals[i].second;
    }

    // std::cout << "DEBUG: min_idx: " << min_idx << "\n";
    // std::cout << "DEBUG: min_vals[min_idx]: "
    //           << min_vals[min_idx].first << " "
    //           << min_vals[min_idx].second << "\n";

    std::int64_t beauty = 0;
    for (std::size_t i = 0; i < num_arrs; i++) {
      auto curr_swap =
          sum_second_mins - min_vals[i].second + min_vals[min_idx].first;
      beauty = std::max(beauty, curr_swap);
    }
    std::cout << beauty << "\n";
  }
}
