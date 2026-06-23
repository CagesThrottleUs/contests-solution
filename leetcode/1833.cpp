#include <array>
#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

class Solution {
  static constexpr std::size_t MAX_ELEMENTS = 100'000 + 1;

 public:
  static auto maxIceCream(std::vector<std::int32_t>& costs, std::int32_t coins)
      -> std::int32_t {
    std::array<std::size_t, MAX_ELEMENTS> freq{};
    freq.fill(0);
    for (const auto& cost : costs) {
      freq.at(static_cast<std::size_t>(cost))++;
    }

    std::int32_t count{0};

    for (std::size_t i{1}; i < freq.size(); i++) {
      auto val = freq.at(i);
      if (val == 0) {
        continue;
      }
      if (coins == 0) {
        break;
      }
      while (std::cmp_greater_equal(coins, i) and val > 0) {
        coins -= static_cast<std::int32_t>(i);
        val--;
        count++;
      }
    }

    return count;
  }
};