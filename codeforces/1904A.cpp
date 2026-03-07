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

#include <cstdint>
#include <iostream>
#include <set>

constexpr std::int64_t SHIFT = 32;

constexpr auto make_pos(int pos_x, int pos_y) -> std::int64_t {
  return (static_cast<std::int64_t>(pos_x)  // NOLINT(hicpp-signed-bitwise)
          << SHIFT) |                       // NOLINT(hicpp-signed-bitwise)
         static_cast<std::uint32_t>(pos_y);
}

void provide_possible_positions(int pos_x, int pos_y, int mov_a, int mov_b,
                                std::set<std::int64_t>& out) {
  out.clear();
  out.insert(make_pos(pos_x + mov_a, pos_y + mov_b));
  out.insert(make_pos(pos_x - mov_a, pos_y + mov_b));
  out.insert(make_pos(pos_x + mov_a, pos_y - mov_b));
  out.insert(make_pos(pos_x - mov_a, pos_y - mov_b));
  out.insert(make_pos(pos_x + mov_b, pos_y + mov_a));
  out.insert(make_pos(pos_x - mov_b, pos_y + mov_a));
  out.insert(make_pos(pos_x + mov_b, pos_y - mov_a));
  out.insert(make_pos(pos_x - mov_b, pos_y - mov_a));
}

void solve() {
  int tests{};
  std::cin >> tests;

  static std::set<std::int64_t> king_pos;
  static std::set<std::int64_t> queen_pos;
  while ((tests--) != 0) {
    int mov_a{};
    int mov_b{};
    std::cin >> mov_a >> mov_b;

    int king_x{};
    int king_y{};
    std::cin >> king_x >> king_y;

    int queen_x{};
    int queen_y{};
    std::cin >> queen_x >> queen_y;

    provide_possible_positions(king_x, king_y, mov_a, mov_b, king_pos);
    provide_possible_positions(queen_x, queen_y, mov_a, mov_b, queen_pos);

    int count = 0;
    for (std::int64_t pos : king_pos) {
      if (queen_pos.contains(pos)) {
        ++count;
      }
    }
    std::cout << count << "\n";
  }
}