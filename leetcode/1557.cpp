#include <cstddef>
#include <cstdint>
#include <vector>

class Solution {
 public:
  static auto findSmallestSetOfVertices(
      std::int32_t num_nodes, std::vector<std::vector<std::int32_t>>& edges)
      -> std::vector<std::int32_t> {
    std::vector<bool> has_incoming(static_cast<std::size_t>(num_nodes), false);
    for (const auto& edge : edges) {
      has_incoming[static_cast<std::size_t>(edge[1])] = true;
    }
    std::vector<std::int32_t> result;
    for (std::int32_t i = 0; i < num_nodes; i++) {
      if (!has_incoming[static_cast<std::size_t>(i)]) {
        result.push_back(i);
      }
    }
    return result;
  }
};