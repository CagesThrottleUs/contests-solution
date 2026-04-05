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
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

using Coord = std::pair<std::int64_t, std::int64_t>;

inline auto compute_distance(const Coord& lhs, const Coord& rhs)
    -> std::int64_t {
  return std::abs(lhs.first - rhs.first) + std::abs(lhs.second - rhs.second);
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t points{};
    std::size_t major_cities{};
    std::size_t start{};
    std::size_t end{};
    std::cin >> points >> major_cities >> start >> end;

    std::vector<Coord> coords;
    coords.reserve(points);

    for (std::size_t i{0}; i < points; i++) {
      std::int64_t pos_x{};
      std::int64_t pos_y{};
      std::cin >> pos_x >> pos_y;
      coords.emplace_back(pos_x, pos_y);
    }

    const Coord& start_coord = coords[start - 1];
    const Coord& end_coord = coords[end - 1];

    // Max Manhattan distance is 4e9; use max/2 so two sentinels can be added
    // without overflow when no major city route exists.
    static constexpr std::int64_t MAX_DIST =
        std::numeric_limits<std::int64_t>::max() / 2;
    auto dist_start_major = MAX_DIST;
    auto dist_end_major = MAX_DIST;

    for (std::size_t i{0}; i < major_cities; i++) {
      dist_start_major =
          std::min(dist_start_major, compute_distance(start_coord, coords[i]));
      dist_end_major =
          std::min(dist_end_major, compute_distance(end_coord, coords[i]));
    }

    std::cout << std::min(compute_distance(start_coord, end_coord),
                          dist_start_major + dist_end_major)
              << '\n';
  }
}