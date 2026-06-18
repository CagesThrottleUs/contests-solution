#include <cstddef>
#include <cstdint>
#include <vector>

class Solution {
 public:
  static auto findJudge(std::int32_t total_people,
                        std::vector<std::vector<std::int32_t>>& trust)
      -> std::int32_t {
    const std::size_t arr_size = static_cast<std::size_t>(total_people) + 1;
    std::vector<std::int32_t> in_edge(arr_size, 0);
    std::vector<std::int32_t> out_edge(arr_size, 0);

    for (const auto& relation : trust) {
      auto start = relation.front();
      auto end = relation.back();
      out_edge.at(static_cast<std::size_t>(start))++;
      in_edge.at(static_cast<std::size_t>(end))++;
    }

    for (std::size_t i{1}; i<arr_size; i++) {
      if (in_edge.at(i) == (total_people - 1) and out_edge.at(i) == 0) {
        return static_cast<std::int32_t>(i);
      }
    }

    return -1;
  }
};