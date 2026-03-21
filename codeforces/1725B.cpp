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

#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
void solve() {
  int num_arr{};
  int max_score{};
  std::cin >> num_arr >> max_score;

  std::vector<int> arr;
  arr.reserve(static_cast<std::size_t>(num_arr));

  for (int i{0}; i < num_arr; i++) {
    int score{};
    std::cin >> score;
    arr.push_back(score);
  }

  std::ranges::sort(arr, std::greater<>());

  int ans{0};
  int rem{num_arr};
  for (const auto& score : arr) {
    auto need = 1 + (max_score / score);
    if (need <= rem) {
      rem -= need;
      ans++;
    } else {
      break;
    }
  }
  std::cout << ans << "\n";
}