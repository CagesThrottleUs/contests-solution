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

#include <cstddef>
#include <iostream>
#include <vector>

auto get_vector(std::size_t size) -> std::vector<int> {
  std::vector<int> vec(size);
  for (auto& elem : vec) {
    std::cin >> elem;
  }
  return vec;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    int num_elems{};
    int window{};
    std::cin >> num_elems >> window;

    auto idx = [](int pos) -> std::size_t {
      return static_cast<std::size_t>(pos);
    };

    const std::vector<int> nums = get_vector(idx(num_elems));
    const std::vector<int> mirror = get_vector(idx(num_elems));

    // Frequency of the first window of 'nums' (values 1..num_elems)
    std::vector<int> freq(idx(num_elems + 1), 0);
    for (int i{0}; i < window; i++) {
      freq[idx(nums[idx(i)])]++;
    }

    bool possible = true;

    for (int i{0}; i < window && possible; i++) {
      const int first_a = nums[idx(i)];
      bool is_mono = true;

      for (int j{i}; j < num_elems; j += window) {
        if (nums[idx(j)] != first_a) {
          is_mono = false;
          break;
        }
      }

      if (!is_mono) {
        // Non-monochromatic chain: mirror must exactly match nums
        for (int j{i}; j < num_elems && possible; j += window) {
          const int cur_b = mirror[idx(j)];
          if (cur_b != -1 && cur_b != nums[idx(j)]) {
            possible = false;
          }
        }
        if (possible && --freq[idx(first_a)] < 0) {
          possible = false;
        }
      } else {
        // Monochromatic chain: mirror must be monochromatic too
        int b_val = -1;
        for (int j{i}; j < num_elems && possible; j += window) {
          const int cur_b = mirror[idx(j)];
          if (cur_b == -1) {
            continue;
          }
          if (b_val == -1) {
            b_val = cur_b;
          } else if (b_val != cur_b) {
            possible = false;
          }
        }
        if (possible && b_val != -1 && --freq[idx(b_val)] < 0) {
          possible = false;
        }
      }
    }

    std::cout << (possible ? "YES" : "NO") << '\n';
  }
}
