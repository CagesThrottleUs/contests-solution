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
#include <functional>
#include <iostream>
#include <vector>

void solve() {
  int num_people{};
  int num_food_items{};
  std::cin >> num_food_items >> num_people;

  std::vector<int> amt_food;
  amt_food.reserve(static_cast<std::size_t>(num_food_items));

  for (int i{0}; i < num_food_items; i++) {
    int amt{};
    std::cin >> amt;
    amt_food.push_back(amt);
  }

  std::ranges::sort(amt_food, std::greater<>());

  std::size_t right{0};

  int ans{0};

  while (right < amt_food.size() and
         right < static_cast<std::size_t>(num_people)) {
    auto window_size = right + 1;
    auto min_people_per_food = num_people / static_cast<int>(window_size);

    auto rem = static_cast<std::size_t>(num_people) % window_size;

    if (rem > 0) {
      ans = std::max(ans,
                     std::min(amt_food[right] / (min_people_per_food),
                              amt_food[rem - 1] / (min_people_per_food + 1)));
    } else {
      ans = std::max(ans, amt_food[right] / min_people_per_food);
    }

    right++;
  }

  std::cout << ans << "\n";
}
