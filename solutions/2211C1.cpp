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
#include <unordered_map>

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    int size{};
    int window_size{};
    std::cin >> size >> window_size;

    std::unordered_map<int, int> a_map;
    for (int i{1}; i <= size; i++) {
      int num{};
      std::cin >> num;
      a_map[num] = i;
    }

    std::unordered_map<int, int> b_map;
    bool is_good{true};
    for (int i{1}; i <= size; i++) {
      int num{};
      std::cin >> num;

      if (num == -1) {
        continue;
      }

      if (b_map.contains(num)) {
        is_good = false;
      }
      b_map[num] = i;
    }

    if (!is_good) {
      std::cout << "NO\n";
      continue;
    }

    for (const auto& [key, pos_b] : b_map) {
      const int pos_a{a_map[key]};
      // pos_a must lie in the intersection of all windows of size k covering pos_b
      if (pos_a < std::min(pos_b, size - window_size + 1) ||
          pos_a > std::max(window_size, pos_b)) {
        is_good = false;
        break;
      }
      // pos_b must lie in the intersection of all windows of size k covering pos_a
      if (pos_b < std::min(pos_a, size - window_size + 1) ||
          pos_b > std::max(window_size, pos_a)) {
        is_good = false;
        break;
      }
    }

    std::cout << (is_good ? "YES" : "NO") << "\n";
  }
}
