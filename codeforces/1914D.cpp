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
#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>

constexpr std::size_t TOTAL_ACTIVITIES = 3;

inline auto get_activities(std::size_t total_days) -> std::array<
    std::array<std::pair<std::uint32_t, std::size_t>, TOTAL_ACTIVITIES>,
    TOTAL_ACTIVITIES> {
  std::array<
      std::array<std::pair<std::uint32_t, std::size_t>, TOTAL_ACTIVITIES>,
      TOTAL_ACTIVITIES>
      activities{};

  for (std::size_t i{0}; i < TOTAL_ACTIVITIES; i++) {
    std::priority_queue<std::pair<std::uint32_t, std::size_t>,
                        std::vector<std::pair<std::uint32_t, std::size_t>>,
                        std::greater<>>
        _pq;
    for (std::size_t j{0}; j < total_days; j++) {
      std::uint32_t activity{};
      std::cin >> activity;
      _pq.emplace(activity, j);
      if (_pq.size() > TOTAL_ACTIVITIES) {
        _pq.pop();
      }
    }
    std::size_t idx = 0;
    while (!_pq.empty()) {
      activities.at(i).at(idx) = _pq.top();
      idx++;
      _pq.pop();
    }
  }
  return activities;
}

void solve() {
  std::int32_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t total_days{};
    std::cin >> total_days;

    auto activities = get_activities(total_days);

    std::uint32_t ans{0};

    for (std::size_t i{0}; i < TOTAL_ACTIVITIES; i++) {
      std::unordered_set<std::size_t> visited{};
      auto ele = activities.at(0).at(i);
      visited.insert(ele.second);
      // std::cout << "DEBUG: ele.first: " << ele.first << "\n";
      // std::cout << "DEBUG: ele.second: " << ele.second << "\n";
      for (std::size_t j{0}; j < TOTAL_ACTIVITIES; j++) {
        auto ele2 = activities.at(1).at(j);
        if (visited.contains(ele2.second)) {
          continue;
        }
        visited.insert(ele2.second);
        // std::cout << "DEBUG: ele2.first: " << ele2.first << "\n";
        // std::cout << "DEBUG: ele2.second: " << ele2.second << "\n";
        for (std::size_t k{0}; k < TOTAL_ACTIVITIES; k++) {
          auto ele3 = activities.at(2).at(k);
          if (visited.contains(ele3.second)) {
            continue;
          }
          visited.insert(ele3.second);
          // std::cout << "DEBUG: ele3.first: " << ele3.first << "\n";
          // std::cout << "DEBUG: ele3.second: " << ele3.second << "\n";
          ans = std::max(ans, ele.first + ele2.first + ele3.first);
          visited.erase(ele3.second);
        }
        visited.erase(ele2.second);
      }
      visited.erase(ele.second);
    }

    std::cout << ans << "\n";
  }
}