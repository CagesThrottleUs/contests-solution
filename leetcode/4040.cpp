#include <algorithm>
#include <cstddef>
#include <utility>
#include <vector>

class Solution {
 private:
  static constexpr int INF = 1e9;

  // Helper function to generate unique (value, min_ops) options per number.
  // Extracted to reduce nesting depth and branch complexity.
  static auto getOptions(int num, int sum) -> std::vector<std::pair<int, int>> {
    std::vector<int> min_cost(static_cast<std::size_t>(sum + 1), INF);

    // 1. Pure multiplications: x * 2^k
    for (int val = num, ops = 0; val <= sum; val *= 2, ++ops) {
      auto idx = static_cast<std::size_t>(val);
      min_cost[idx] = std::min(min_cost[idx], ops);
    }

    // 2. Pure divisions: floor(x / 2^p)
    for (int val = num / 2, ops = 1; val > 0; val /= 2, ++ops) {
      if (val <= sum) {
        auto idx = static_cast<std::size_t>(val);
        min_cost[idx] = std::min(min_cost[idx], ops);
      }
    }

    std::vector<std::pair<int, int>> options;
    for (int loop = 1; loop <= sum; ++loop) {
      auto idx = static_cast<std::size_t>(loop);
      if (min_cost[idx] != INF) {
        options.emplace_back(loop, min_cost[idx]);
      }
    }
    return options;
  }

 public:
  static auto minOperations(std::vector<int>& nums, int sum) -> int {
    std::vector<int> mem(static_cast<std::size_t>(sum + 1), INF);
    mem[0] = 0;

    for (int num : nums) {
      const auto options = getOptions(num, sum);
      auto next_dp = mem;

      for (const auto& [val, cost] : options) {
        for (int looper = sum - val; looper >= 0; --looper) {
          auto idx = static_cast<std::size_t>(looper);
          if (mem[idx] == INF) {
            continue;
          }

          auto target_idx = static_cast<std::size_t>(val) + idx;
          next_dp[target_idx] = std::min(next_dp[target_idx], mem[idx] + cost);
        }
      }
      mem = std::move(next_dp);
    }

    auto final_idx = static_cast<std::size_t>(sum);
    return mem[final_idx] == INF ? -1 : mem[final_idx];
  }
};