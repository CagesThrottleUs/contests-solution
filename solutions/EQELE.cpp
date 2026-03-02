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
#include <unordered_map>
#include <vector>

auto work() -> int {
  int size{};
  std::cin >> size;

  std::unordered_map<int, int> last_idx;
  std::vector<int> dp(size, 0);

  for (int i = 0; i < size; i++) {
    int num{};
    std::cin >> num;
    if (last_idx.count(num) == 1) {
      dp[i] = std::max(dp[i], dp[last_idx[num]] + 1);
      last_idx.erase(num);
    } else {
      last_idx[num] = i;
    }
    if (i > 0) dp[i] = std::max(dp[i], dp[i - 1]);
  }
  return 2 * dp[size - 1];
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
