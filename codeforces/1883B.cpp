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

#include <array>
#include <cstddef>
#include <iostream>

constexpr std::size_t ALPHABET_SIZE = 26;

auto can_grab_count(const std::array<std::size_t, ALPHABET_SIZE>& freq,
                    std::size_t rem_cnt) -> bool {
  std::size_t count{0};
  for (std::size_t i{0}; i < ALPHABET_SIZE; i++) {
    count += (freq.at(i) - (freq.at(i) % 2));
  }
  return count >= rem_cnt;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t str_len{};
    std::size_t remove_cnt{};
    std::cin >> str_len >> remove_cnt;

    std::array<std::size_t, ALPHABET_SIZE> freq{};
    freq.fill(0);

    for (std::size_t i{0}; i < str_len; i++) {
      char input{};
      std::cin >> input;
      freq.at(static_cast<std::size_t>(input - 'a'))++;
    }

    std::size_t lambda{str_len - remove_cnt};

    if (lambda % 2 == 0) {
      if (can_grab_count(freq, lambda)) {
        std::cout << "YES\n";
      } else {
        std::cout << "NO\n";
      }
    } else {
      if (can_grab_count(freq, lambda - 1) && remove_cnt >= 0) {
        std::cout << "YES\n";
      } else {
        std::cout << "NO\n";
      }
    }
  }
}