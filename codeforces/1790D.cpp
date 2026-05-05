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

// #include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <map>

void solve() {
  std::int32_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    std::cin >> size;

    std::map<std::uint32_t, std::size_t> freq_map;
    for (std::size_t i{0}; i < size; i++) {
      std::uint32_t num{};
      std::cin >> num;
      freq_map[num]++;
    }

    std::size_t counts{0};

    // while (!freq_map.empty()) {
    //   auto first_key = freq_map.begin()->first;

    //   std::uint32_t count{0};
    //   auto min_count = freq_map.begin()->second;

    //   while (freq_map.contains(first_key + count)) {
    //     min_count = std::min(min_count, freq_map.at(first_key + count));
    //     count++;
    //   }

    //   counts += min_count;

    //   for (std::uint32_t i{0}; i < count; i++) {
    //     freq_map[first_key + i] -= min_count;
    //     if (freq_map[first_key + i] == 0) {
    //       freq_map.erase(first_key + i);
    //     }
    //   }
    // }

    for (const auto& [key, count] : freq_map) {
      if (freq_map[key] < freq_map[key - 1]) {
        continue;
      }
      // We only add those that we need
      counts += (freq_map[key] - freq_map[key - 1]);
    }

    std::cout << counts << "\n";
  }
}