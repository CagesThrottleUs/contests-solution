#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

class Solution {
 private:
  static constexpr int INF = 1e9;

  // Generates (value, min_ops) options using: (x >> p) << k
  static auto getOptions(int num, int sum) -> std::vector<std::pair<int, int>> {
    std::vector<int> min_cost(static_cast<std::size_t>(sum + 1), INF);

    // p = number of initial divisions
    int base_val = num;
    int power = 0;

    while (base_val > 0) {
      // k = number of subsequent multiplications
      std::int64_t val = base_val;
      int counter = 0;

      while (val <= sum) {
        auto idx = static_cast<std::size_t>(val);
        min_cost[idx] = std::min(min_cost[idx], power + counter);
        val *= 2;
        counter++;
      }

      base_val /= 2;
      power++;
    }

    std::vector<std::pair<int, int>> options;
    for (int loop_var = 1; loop_var <= sum; ++loop_var) {
      auto idx = static_cast<std::size_t>(loop_var);
      if (min_cost[idx] != INF) {
        options.emplace_back(loop_var, min_cost[idx]);
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