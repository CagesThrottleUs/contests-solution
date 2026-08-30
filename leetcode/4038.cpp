#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <vector>

enum class State : uint8_t {
  INITIALIZED,
  FOUND,
  FALSY,
};

class Solution {
 public:
  static auto countSpecialIntegers(std::vector<std::int32_t>& nums)
      -> std::int32_t {
    std::unordered_map<std::int32_t, State> vals;
    for (std::size_t i{0}; i < nums.size(); i++) {
      const auto& num = nums[i];
      if (!vals.contains(num)) {
        vals[num] = State::FOUND;
        continue;
      }
      if (i > 0 and nums[i - 1] != num and vals[num] == State::FOUND) {
        vals[num] = State::FALSY;
        continue;
      }
    }

    std::int32_t count{0};
    for (const auto& [key, val] : vals) {
      if (val == State::FOUND) {
        count++;
      }
    }

    return count;
  }
};