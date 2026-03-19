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
#include <iostream>
#include <unordered_set>
#include <vector>

void add(std::unordered_set<int>& visited, int ele, int max_diff, int ele_cnt) {
  auto min_ele = std::max(1, ele - max_diff);
  auto max_ele = std::min(ele + max_diff, ele_cnt);
  for (int i{min_ele}; i <= max_ele; i++) {
    visited.insert(i);
  }
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    int ele_cnt{};
    std::cin >> ele_cnt;
    int max_diff{};
    std::cin >> max_diff;

    std::vector<int> eles;
    for (int i{1}; i <= ele_cnt; i++) {
      int ele{};
      std::cin >> ele;
      if (ele == 1) {
        eles.push_back(i);
      }
    }

    if (eles.empty()) {
      std::cout << "No\n";
      continue;
    }

    bool is_possible = true;

    std::unordered_set<int> visited;
    visited.reserve(static_cast<std::size_t>(ele_cnt));
    add(visited, eles[0], max_diff, ele_cnt);

    for (std::size_t i{1}; i < eles.size(); i++) {
      if (eles[i] - eles[i - 1] <= max_diff) {
        is_possible = false;
        break;
      }
      add(visited, eles[i], max_diff, ele_cnt);
    }
    // std::cout << "visited.size(): " << visited.size() << "\n";
    // std::cout << "is_possible: " << is_possible << "\n";
    is_possible =
        is_possible && (visited.size() == static_cast<std::size_t>(ele_cnt));
    std::cout << (is_possible ? "Yes\n" : "No\n");
  }
}
