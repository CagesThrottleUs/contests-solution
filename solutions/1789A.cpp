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

#include <cstddef>
#include <iostream>
#include <numeric>
#include <vector>

auto check_gcd(const std::vector<int> &arr) -> bool {
  bool has_2{false};
  bool has_even{false};
  const auto sz = arr.size();

  // eager checks for gcd(1, anything) = 1 and gcd(2, even) <= 2
  for (std::size_t i{0}; i < sz; ++i) {
    const int x = arr[i];
    if (x == 1) {
      return true;  // gcd(1, anything) = 1
    }
    if (x == 2) {
      has_2 = true;
    }
    if ((x & 1) == 0) {
      has_even = true;
    }
  }
  if (has_2 && has_even) {
    return true;  // gcd(2, even) <= 2
  }

  for (std::size_t i{0}; i < sz; ++i) {
    for (std::size_t j{i + 1}; j < sz; ++j) {
      if (std::gcd(arr[i], arr[j]) <= 2) {
        return true;
      }
    }
  }
  return false;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    int n{};
    std::cin >> n;
    std::vector<int> arr;
    arr.reserve(static_cast<size_t>(n));
    for (int i{0}; i < n; i++) {
      int input{};
      std::cin >> input;
      arr.push_back(input);
    }
    auto sol = check_gcd(arr);
    std::cout << (sol ? "YES" : "NO") << "\n";
  }
}
