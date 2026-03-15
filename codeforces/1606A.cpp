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
#include <stack>
#include <string>

void fill_stack(std::stack<std::pair<std::size_t, bool>>& stk,
                const std::string& str) {
  for (std::size_t i{1}; i < str.length(); i++) {
    if (str[i] == 'a' and str[i - 1] == 'b') {
      if (stk.empty() || !stk.top().second) {
        stk.emplace(i - 1, false);
      } else {
        stk.pop();
      }
    } else if (str[i] == 'b' and str[i - 1] == 'a') {
      if (stk.empty() || stk.top().second) {
        stk.emplace(i - 1, true);
      } else {
        stk.pop();
      }
    }
  }
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::stack<std::pair<std::size_t, bool>> stk;  // <index, is_a>

    std::string str{};
    std::cin >> str;

    fill_stack(stk, str);

    // std::cout << "Stack size: " << stk.size() << "\n";

    if (stk.empty()) {
      std::cout << str << "\n";
      continue;
    }

    auto ele = stk.top();
    stk.pop();

    // std::cout << "Element: " << ele.first << ", " << ele.second << "\n";
    if (ele.first == str.length() - 2) {
      // std::cout << "Setting last character to destroy\n";
      str[ele.first + 1] = ele.second ? 'a' : 'b';
    } else {
      str.back() = ele.second ? 'a' : 'b';
    }

    std::cout << str << "\n";
  }
}