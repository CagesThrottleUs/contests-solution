/*
 *   MIT License
 *
 *   Copyright (c) 2026 CagesThrottleUs
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 */

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

// Single pass to collect all three position vectors (cache-friendly for long s).
void get_positions(const std::string &s,
                   std::vector<std::size_t> &a_pos,
                   std::vector<std::size_t> &b_pos,
                   std::vector<std::size_t> &c_pos) {
  a_pos.clear();
  b_pos.clear();
  c_pos.clear();
  for (std::size_t i = 0; i < s.size(); ++i) {
    if (s[i] == 'A') a_pos.push_back(i);
    else if (s[i] == 'B') b_pos.push_back(i);
    else if (s[i] == 'C') c_pos.push_back(i);
  }
}

void solve() {
  std::string s;
  std::cin >> s;

  std::vector<std::size_t> a_pos, b_pos, c_pos;
  get_positions(s, a_pos, b_pos, c_pos);

  if (a_pos.empty() || b_pos.empty() || c_pos.empty()) {
    std::cout << "0\n";
    return;
  }

  std::size_t c_idx = c_pos.size() - 1;
  std::size_t b_max = b_pos.size() - 1;
  std::size_t a_max = a_pos.size() - 1;
  int cnt_op = 0;

  while (true) {
    // Rightmost B in [0, b_max] with b_pos[b_idx] < c_pos[c_idx]
    auto it_b = std::lower_bound(b_pos.begin(), b_pos.begin() + b_max + 1,
                                 c_pos[c_idx]);
    if (it_b == b_pos.begin()) {
      if (c_idx == 0) break;
      --c_idx;
      continue;
    }
    std::size_t b_idx = static_cast<std::size_t>(it_b - b_pos.begin()) - 1;

    // Rightmost A in [0, a_max] with a_pos[a_idx] < b_pos[b_idx]
    auto it_a = std::lower_bound(a_pos.begin(), a_pos.begin() + a_max + 1,
                                 b_pos[b_idx]);
    if (it_a == a_pos.begin()) {
      if (c_idx == 0) break;
      --c_idx;
      continue;
    }
    std::size_t a_idx = static_cast<std::size_t>(it_a - a_pos.begin()) - 1;

    ++cnt_op;
    if (b_idx == 0 || a_idx == 0) break;
    b_max = b_idx - 1;
    a_max = a_idx - 1;
    if (c_idx == 0) break;
    --c_idx;
  }

  std::cout << cnt_op << "\n";
}