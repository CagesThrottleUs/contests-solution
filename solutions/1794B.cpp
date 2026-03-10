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

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

void print(const std::vector<std::uint64_t>& arr) {
  if (arr.empty()) {
    return;
  }
  std::cout << arr.front();
  for (std::size_t i{1}; i < arr.size(); i++) {
    std::cout << " " << arr[i];
  }
  std::cout << "\n";
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    std::cin >> size;

    auto max_ops = 2 * size;
    std::size_t ops{0};

    std::vector<std::uint64_t> arr;
    arr.reserve(size);

    // first element
    std::uint64_t val{};
    std::cin >> val;

    if (val == 1) {
      ops += 1;
      val++;
    }
    arr.push_back(val);

    for (std::size_t i{1}; i < size; i++) {
      std::uint64_t val{};
      std::cin >> val;

      if (val == 1) {
        ops++;
        val++;
        while (val % arr.back() == 0) {
          ops++;
          val++;
        }
      } else if (val % arr.back() == 0) {
        ops++;
        val++;
      }
      arr.push_back(val);
    }

    if (ops > max_ops) {
      throw std::runtime_error("Too many operations");
    }

    print(arr);
  }
}
