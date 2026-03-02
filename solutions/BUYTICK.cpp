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

#include <iostream>
#include <queue>
#include <vector>

auto work() -> int {
  int n, k;
  std::cin >> n >> k;
  std::priority_queue<int> pq;

  std::vector<int> prices(n);
  for (int i = 0; i < n; i++) {
    std::cin >> prices[i];
  }

  int cnt_available = 0;

  for (int i = 0; i < n; i++) {
    char ch;
    std::cin >> ch;
    if (ch == '0') {
      cnt_available++;
      pq.push(prices[i]);
      if (pq.size() > k) {
        pq.pop();
      }
    }
  }

  if (cnt_available < k) {
    return -1;
  }

  int sol = 0;
  while (!pq.empty()) {
    sol += pq.top();
    pq.pop();
  }

  return sol;
}

void solve() {
  int num_test_cases{};
  std::cin >> num_test_cases;

  while (num_test_cases > 0) {
    num_test_cases--;
    auto sol = work();
    std::cout << sol << "\n";
  }
}
