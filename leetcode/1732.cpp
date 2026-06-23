#include <algorithm>
#include <vector>

class Solution {
 public:
  static auto largestAltitude(std::vector<std::int32_t>& gain) -> std::int32_t {
    std::int32_t max_height = 0;
    std::int32_t curr_height = 0;

    for (const auto& delta : gain) {
      curr_height += delta;
      max_height = std::max(max_height, curr_height);
    }

    return max_height;
  }
};