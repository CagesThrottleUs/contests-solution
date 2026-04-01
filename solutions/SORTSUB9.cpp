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

#include <cstddef>
#include <cstdint>
#include <iostream>

enum class State : std::uint8_t {
  INCREASING,
  DECREASING,
};

void solve() {
  std::size_t num_ele{};
  std::cin >> num_ele;

  int last{};
  std::cin >> last;

  std::size_t left{1};
  State running_state{State::DECREASING};
  std::size_t cnt{1};

  std::size_t plateau_start{1};

  for (std::size_t i{2}; i <= num_ele; ++i) {
    int cur{};
    std::cin >> cur;

    if (cur > last) {
      running_state = State::INCREASING;
    } else if (cur < last) {
      if (running_state == State::INCREASING) {
        // We were going up, now we are going down.
        // The new "non-increasing" start is the beginning of the plateau
        // of values that were equal to 'last'.
        left = plateau_start;
        running_state = State::DECREASING;
      }
    }

    // Update plateau: if value changes, the new plateau starts here
    if (cur != last) {
      plateau_start = i;
    }

    cnt += (i - left + 1);
    last = cur;
  }

  std::cout << cnt << "\n";
}
