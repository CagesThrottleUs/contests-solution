#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <string>

constexpr std::size_t NUM_CHARACTERS = 26;
constexpr std::int32_t NOT_DETERMINED = -1;
constexpr std::int32_t REPEATED = std::numeric_limits<std::int32_t>::max();

class Solution {
 public:
  static auto firstUniqChar(std::string str) -> std::int32_t {
    std::array<std::int32_t, NUM_CHARACTERS> last_good_idx{};
    last_good_idx.fill(NOT_DETERMINED);

    for (std::size_t i{0}; i < str.size(); i++) {
      auto idx = static_cast<std::size_t>(str.at(i) - 'a');
      auto& val = last_good_idx.at(idx);
      if (val == REPEATED) {
        continue;
      }
      if (val == NOT_DETERMINED) {
        val = static_cast<std::int32_t>(i);
      } else {
        val = REPEATED;
      }
    }

    for (auto& val: last_good_idx) {
      if (val == NOT_DETERMINED) {
        val = REPEATED;
      }
    }

    auto ans = std::ranges::min(last_good_idx);

    return ans == REPEATED ? -1 : ans;
  }
};