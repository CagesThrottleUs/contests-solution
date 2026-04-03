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

inline auto get_first_experience(std::size_t total_quests) -> std::vector<int> {
  std::vector<int> first_experience;
  first_experience.reserve(total_quests);

  int prefix{0};
  for (std::size_t i{0}; i < total_quests; i++) {
    int curr{};
    std::cin >> curr;
    prefix += curr;
    first_experience.push_back(prefix);
  }

  return first_experience;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t total_quests{};
    std::size_t completable{};
    std::cin >> total_quests >> completable;

    std::vector<int> first_experience = get_first_experience(total_quests);

    int max_experience{0};
    int running_max{0};
    const std::size_t limit{std::min(total_quests, completable)};

    for (std::size_t i{0}; i < total_quests; i++) {
      int curr{};
      std::cin >> curr;
      running_max = std::max(running_max, curr);

      if (i < limit) {
        max_experience = std::max(
            max_experience,
            first_experience[i] +
                (static_cast<int>(completable - i - 1) * running_max));
      }
    }

    std::cout << max_experience << "\n";
  }
}