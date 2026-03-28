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
#include <vector>

void solve() {
  int num_emp{};
  int num_dept{};
  std::cin >> num_emp >> num_dept;

  std::vector<int> dept_map(static_cast<std::size_t>(num_dept + 1), 0);

  for (int i = 0; i < num_emp; i++) {
    std::size_t curr_term_dept{};
    std::size_t next_term_dept{};
    std::cin >> curr_term_dept >> next_term_dept;

    dept_map[next_term_dept]++;
    dept_map[curr_term_dept]--;
  }

  for (std::size_t i = 1; i <= static_cast<std::size_t>(num_dept); i++) {
    std::cout << dept_map[i] << "\n";
  }
}