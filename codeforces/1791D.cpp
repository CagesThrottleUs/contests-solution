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
#include <bitset>
#include <cstddef>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

constexpr std::size_t NUM_ALPHABET = 26;

auto get_freq_sums(const std::string_view& str) -> std::vector<std::size_t> {
  std::vector<std::size_t> sums(str.size(), 0);
  std::bitset<NUM_ALPHABET> fwd;
  fwd[static_cast<std::size_t>(str[0] - 'a')] = true;
  sums[0] = 1;
  std::bitset<NUM_ALPHABET> rev;
  for (std::size_t i{1}; i < str.size(); i++) {
    fwd[static_cast<std::size_t>(str[i] - 'a')] = true;
    sums[i] += fwd.count();
    rev[static_cast<std::size_t>(str[str.size() - i] - 'a')] = true;
    sums[sums.size() - i - 1] += rev.count();
  }
  return sums;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t str_len{};
    std::cin >> str_len;

    std::string str;
    str.reserve(str_len);
    std::cin >> str;

    auto sums = get_freq_sums(str);
    std::cout << *std::ranges::max_element(sums) << "\n";
  }
}