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

#include <iostream>

#ifdef __GNUC__
#ifndef __clang__
#pragma GCC optimize("O3", "unroll-loops")
#endif
#endif

void speedup() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

// Forward declaration - to be implemented in problem file
void solve();

auto main() -> int {
    speedup();
    solve();
    return 0;
}

// Include the problem-specific implementation

#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

void print(std::vector<int> &arr) {
  if (arr.empty()) {
    std::cout << "empty\n";
    return;
  }
  std::cout << arr.front();
  for (int i = 1; i < arr.size(); i++) {
    std::cout << " " << arr[i];
  }
  std::cout << "\n";
}

void print(std::deque<int> &arr) {
  if (arr.empty()) {
    std::cout << "empty\n";
    return;
  }
  std::cout << arr.front();
  for (int i = 1; i < arr.size(); i++) {
    std::cout << " " << arr[i];
  }
  std::cout << "\n";
}

void pls_rotate(std::deque<int> &arr) {
  auto min_ele = std::min_element(arr.begin(), arr.end());
  std::rotate(arr.begin(), min_ele, arr.end());
}

void work() {
  int num_eles{};
  int first_portal{};
  int second_portal{};
  std::cin >> num_eles >> first_portal >> second_portal;
//   std::cout << "num_eles: " << num_eles << ", first_portal: " << first_portal
//             << ", second_portal: " << second_portal << "\n";

  first_portal--;
  second_portal--;

  std::deque<int> rem;
  std::deque<int> rotated;

  for (int i = 0; i < num_eles; i++) {
    int num{};
    std::cin >> num;

    // std::cout << "num: " << num << ", i: " << i << "\n";

    if (first_portal < i && i <= second_portal) {
      rotated.push_back(num);
    } else {
      rem.push_back(num);
    }
  }

//   std::cout << "rem: ";
//   print(rem);
//   std::cout << "rotated: ";
//   print(rotated);

  pls_rotate(rotated);

  std::vector<int> ans;
  while (!rem.empty() && rotated.front() > rem.front()) {
    ans.push_back(rem.front());
    rem.pop_front();
  }

//   std::cout << "ans: ";
//   print(ans);

  while (!rotated.empty()) {
    ans.push_back(rotated.front());
    rotated.pop_front();
  }

//   std::cout << "ans: ";
//   print(ans);

  while (!rem.empty()) {
    ans.push_back(rem.front());
    rem.pop_front();
  }

//   std::cout << "ans: ";
  print(ans);
}

void solve() {
  int num_test_cases{};
  std::cin >> num_test_cases;

  while (num_test_cases > 0) {
    num_test_cases--;
    work();
  }
}
