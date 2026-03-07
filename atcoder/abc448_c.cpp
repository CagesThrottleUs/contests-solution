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
#include <set>
#include <unordered_set>
#include <utility>

auto find_min(const std::set<std::pair<int, int>, std::less<>>& min_set,
              const std::unordered_set<int>& seq_set) -> int {
  for (const auto& [value, index] : min_set) {
    if (!seq_set.contains(index)) {
      return value;
    }
  }
  return -1;
}

void solve() {
  int len{};
  int queries{};
  std::cin >> len >> queries;

  std::set<std::pair<int, int>, std::less<>> min_set;

  for (int i{0}; i < len; i++) {
    int value{};
    std::cin >> value;
    min_set.insert({value, i + 1});
  }

  int seq_len{};
  std::unordered_set<int> seq_set;

  while ((queries--) != 0) {
    std::cin >> seq_len;
    seq_set.reserve(static_cast<std::size_t>(seq_len));

    for (int i{0}; i < seq_len; i++) {
      int value{};
      std::cin >> value;
      seq_set.insert(value);
    }

    auto min = find_min(min_set, seq_set);

    std::cout << min << "\n";

    seq_set.clear();
  }
}