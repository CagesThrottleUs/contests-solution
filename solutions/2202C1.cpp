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
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 300005;
int bit[MAXN], last_pos[MAXN];

void update(int idx, int val, int limit) {
  for (; idx <= limit; idx += idx & -idx)
    bit[idx] = max(bit[idx], val);
}

int query(int idx) {
  int res = 0;
  for (; idx > 0; idx -= idx & -idx)
    res = max(res, bit[idx]);
  return res;
}

void work() {
  int n;
  cin >> n;
  vector<int> a(n), sorted_a;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sorted_a.push_back(a[i]);
  }
  sort(sorted_a.begin(), sorted_a.end());
  sorted_a.erase(unique(sorted_a.begin(), sorted_a.end()), sorted_a.end());

  int u = sorted_a.size();
  for (int i = 1; i <= u; ++i) {
    bit[i] = 0;
    last_pos[i] = 0;
  }

  auto get_id = [&](int x) {
    auto it = lower_bound(sorted_a.begin(), sorted_a.end(), x);
    return (it != sorted_a.end() && *it == x) ? (int)(it - sorted_a.begin() + 1)
                                              : -1;
  };

  int roots = 0;
  for (int i = 0; i < n; ++i) {
    int v = get_id(a[i]), v_prev = get_id(a[i] - 1);
    bool gen = false;
    if (v_prev != -1 && last_pos[v_prev] > 0) {
      if (query(v_prev) <= last_pos[v_prev])
        gen = true;
    }
    if (!gen)
      roots++;
    last_pos[v] = i + 1;
    update(v, i + 1, u);
  }
  cout << roots << "\n";
}

void solve() {
  int num_test_case{};
  std::cin >> num_test_case;
  while (num_test_case > 0) {
    num_test_case--;
    work();
  }
}
