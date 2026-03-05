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
#include <unordered_set>
#include <vector>

auto play(std::vector<int> dish, int start) -> int {
  int cnt_non_zero = dish.size();

  int curr = start;
  int last = 0;

  while (cnt_non_zero > 0) {
    if (dish[curr] > 0) {
      dish[curr]--;
      cnt_non_zero -= (dish[curr] == 0) ? 1 : 0;
    }
    last = curr;
    curr = (curr + 1) % dish.size();
  }

  return last;
}

auto work() -> int {
  int n_people{};
  std::cin >> n_people;

  std::vector<int> dish_cnt(n_people);
  for (int i = 0; i < n_people; i++) {
    std::cin >> dish_cnt[i];
  }

  // start from first person
  std::unordered_set<int> winners;
  for (int i = 0; i < n_people; i++) {
    winners.insert(play(dish_cnt, i));
  }

  return winners.size();
}

void solve() {
  int num_test_cases{};
  std::cin >> num_test_cases;

  while (num_test_cases > 0) {
    num_test_cases--;
    std::cout << work() << "\n";
  }
}