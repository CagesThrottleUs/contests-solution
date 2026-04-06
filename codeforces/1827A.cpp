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
#include <functional>
#include <iostream>
#include <vector>

constexpr auto MOD = static_cast<std::int64_t>(1e9 + 7);

inline auto get_inputs(std::vector<int>& arr_a, std::vector<int>& arr_b)
    -> void {
  std::size_t size{};
  std::cin >> size;

  arr_a.reserve(size);
  arr_b.reserve(size);

  for (std::size_t i{0}; i < size; i++) {
    int num{};
    std::cin >> num;
    arr_a.push_back(num);
  }

  for (std::size_t i{0}; i < size; i++) {
    int num{};
    std::cin >> num;
    arr_b.push_back(num);
  }
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::vector<int> arr_a;
    std::vector<int> arr_b;
    get_inputs(arr_a, arr_b);

    std::ranges::sort(arr_a, std::greater<>());
    std::ranges::sort(arr_b, std::greater<>());

    std::vector<int> choices(arr_b.size(), 0);

    std::size_t a_idx{0};

    for (std::size_t i{0}; i < arr_b.size(); i++) {
      while (a_idx < arr_a.size() && arr_a[a_idx] > arr_b[i]) {
        a_idx++;
      }
      choices[i] = static_cast<int>(a_idx);
      choices[i] = std::max(0, choices[i] - static_cast<int>(i));
    }

    std::int64_t ans{1};
    for (const auto& choice : choices) {
      ans = (ans * choice) % MOD;
    }
    std::cout << ans << "\n";
  }
}