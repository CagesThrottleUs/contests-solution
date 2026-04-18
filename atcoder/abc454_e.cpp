/*
 * MIT License
 *
 * Copyright (c) 2026 CagesThrottleUs
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <cstdint>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

struct Bounds {
  std::int32_t row_lo;
  std::int32_t col_lo;
  std::int32_t row_hi;
  std::int32_t col_hi;
};

void strip_top(Bounds& bnd, std::string& path) {
  for (std::int32_t col = bnd.col_lo; col < bnd.col_hi; ++col) {
    path += 'R';
  }
  path += 'D';
  for (std::int32_t col = bnd.col_hi; col > bnd.col_lo; --col) {
    path += 'L';
  }
  path += 'D';
  bnd.row_lo += 2;
}

void strip_left(Bounds& bnd, std::string& path) {
  for (std::int32_t row = bnd.row_lo; row < bnd.row_hi; ++row) {
    path += 'D';
  }
  path += 'R';
  for (std::int32_t row = bnd.row_hi; row > bnd.row_lo; --row) {
    path += 'U';
  }
  path += 'R';
  bnd.col_lo += 2;
}

auto make_bottom_suffix(const Bounds& bnd) -> std::string {
  std::string suffix;
  suffix += 'D';
  for (std::int32_t col = bnd.col_hi; col > bnd.col_lo; --col) {
    suffix += 'L';
  }
  suffix += 'D';
  for (std::int32_t col = bnd.col_lo; col < bnd.col_hi; ++col) {
    suffix += 'R';
  }
  return suffix;
}

auto make_right_suffix(const Bounds& bnd) -> std::string {
  std::string suffix;
  suffix += 'R';
  for (std::int32_t row = bnd.row_hi; row > bnd.row_lo; --row) {
    suffix += 'U';
  }
  suffix += 'R';
  for (std::int32_t row = bnd.row_lo; row < bnd.row_hi; ++row) {
    suffix += 'D';
  }
  return suffix;
}

// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
void build_path(std::int32_t grid_size, std::int32_t skip_row,
                std::int32_t skip_col, std::string& path) {
  Bounds bnd{
      .row_lo = 1, .col_lo = 1, .row_hi = grid_size, .col_hi = grid_size};
  std::vector<std::string> deferred;

  while (bnd.row_hi - bnd.row_lo + 1 > 2 || bnd.col_hi - bnd.col_lo + 1 > 2) {
    std::int32_t rows = bnd.row_hi - bnd.row_lo + 1;
    std::int32_t cols = bnd.col_hi - bnd.col_lo + 1;

    if (rows > 2 && skip_row > bnd.row_lo + 1) {
      strip_top(bnd, path);
    } else if (cols > 2 && skip_col > bnd.col_lo + 1) {
      strip_left(bnd, path);
    } else if (rows > 2 && skip_row < bnd.row_hi - 1) {
      deferred.push_back(make_bottom_suffix(bnd));
      bnd.row_hi -= 2;
    } else {
      deferred.push_back(make_right_suffix(bnd));
      bnd.col_hi -= 2;
    }
  }

  path += (skip_row == bnd.row_lo && skip_col == bnd.col_lo + 1) ? "DR" : "RD";

  for (const auto& seg : std::views::reverse(deferred)) {
    path += seg;
  }
}

void solve() {
  std::int32_t tests{};
  if (!(std::cin >> tests)) {
    return;
  }

  while ((tests--) != 0) {
    std::int32_t grid_size{};
    std::int32_t skip_x{};
    std::int32_t skip_y{};
    std::cin >> grid_size >> skip_x >> skip_y;

    // Condition for existence: N must be even and (A+B) must be odd.
    // This ensures the skipped cell has a different 'color' than the start/end
    // cells.
    if ((grid_size % 2 != 0) || ((skip_x + skip_y) % 2 == 0)) {
      std::cout << "No\n";
      continue;
    }

    std::cout << "Yes\n";
    std::string path;
    path.reserve(static_cast<std::size_t>(grid_size) *
                 static_cast<std::size_t>(grid_size));
    build_path(grid_size, skip_x, skip_y, path);
    std::cout << path << "\n";
  }
}