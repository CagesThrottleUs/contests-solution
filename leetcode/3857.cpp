#include <algorithm>
#include <limits>
#include <vector>

class Solution {
public:
  int minCost(int n) {
    std::vector<int> dp(n + 1, 0);
    for (int i = 2; i <= n; i++) {
      dp[i] = std::numeric_limits<int>::max();
      for (int j = 1; j <= i / 2; j++) {
        dp[i] = std::min(dp[i], dp[j] + dp[i - j] + (j * (i - j)));
      }
    }
    return dp[n];
  }
};