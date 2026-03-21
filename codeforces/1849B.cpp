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
#include <iostream>
#include <vector>

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t num_monsters{};
    std::cin >> num_monsters;

    int dmg_op{};
    std::cin >> dmg_op;

    // r_i = ((h_i - 1) % d) + 1: the monster's health when it gets the kill
    // hit. Kill order: descending r (higher r dies first), ties by ascending
    // idx.
    std::vector<std::pair<int, std::size_t>> monsters(num_monsters);
    for (std::size_t i = 1; i <= num_monsters; i++) {
      int health{};
      std::cin >> health;
      monsters[i - 1] = {((health - 1) % dmg_op) + 1, i};
    }

    std::ranges::stable_sort(monsters,
                             [](const auto& lhs, const auto& rhs) -> bool {
                               return lhs.first > rhs.first;
                             });

    for (const auto& [_not_used, idx] : monsters) {
      std::cout << idx << " ";
    }
    std::cout << "\n";
  }
}