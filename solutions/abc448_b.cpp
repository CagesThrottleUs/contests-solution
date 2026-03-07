/*
 *   MIT License
 *
 *   Copyright (c) 2026 CagesThrottleUs
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 */

#include <iostream>

#ifdef __GNUC__
#ifndef __clang__
#pragma GCC optimize("O3", "unroll-loops")
#endif
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
#include <iostream>
#include <vector>

void solve() {
  int dishes{};
  int spices{};
  std::cin >> dishes >> spices;

  std::vector<int> spices_available(static_cast<std::size_t>(spices), 0);

  for (int i{0}; i < spices; i++) {
    int max_spice{};
    std::cin >> max_spice;
    spices_available.at(static_cast<std::size_t>(i)) = max_spice;
  }

  std::vector<int> max_spices_consumed(static_cast<std::size_t>(spices), 0);

  for (int i{0}; i < dishes; i++) {
    int spice_id{};
    int upper_lim{};
    std::cin >> spice_id >> upper_lim;
    spice_id -= 1;
    max_spices_consumed.at(static_cast<std::size_t>(spice_id)) += upper_lim;
  }

  int total_spices_consumed{0};

  for (int i{0}; i < spices; i++) {
    total_spices_consumed +=
        std::min(max_spices_consumed.at(static_cast<std::size_t>(i)),
                 spices_available.at(static_cast<std::size_t>(i)));
  }

  std::cout << total_spices_consumed << "\n";
}
