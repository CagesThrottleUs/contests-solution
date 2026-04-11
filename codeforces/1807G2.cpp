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
#include <cstdint>
#include <iostream>
#include <iterator>
#include <map>

void print_map(const std::map<std::uint64_t, std::uint64_t> &map) {
  for (auto itr : map) {
    std::cout << itr.first << "->" << itr.second << "\n";
  }
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    std::cin >> size;

    std::map<std::uint64_t, std::uint64_t> key_count;
    for (std::size_t i{0}; i < size; i++) {
      std::uint64_t key{};
      std::cin >> key;
      key_count[key]++;
    }

    // print_map(key_count);

    if (key_count.begin()->first != 1) {
      std::cout << "NO\n";
      continue;
    }

    std::uint64_t sum{key_count.begin()->second};
    bool impossible{false};
    for (auto itr = std::next(key_count.begin()); itr != key_count.end();
         ++itr) {
      if (sum < itr->first) {
        impossible = true;
        break;
      }
      sum += itr->second * itr->first;
    }

    std::cout << (impossible ? "NO\n" : "YES\n");
  }
}