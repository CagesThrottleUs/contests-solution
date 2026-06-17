#include <array>
#include <cctype>
#include <cstddef>
#include <cstdint>
#include <queue>
#include <string>
#include <utility>
#include <vector>

struct Node {
  std::size_t pos_x;
  std::size_t pos_y;
  std::uint8_t keys_found;
  std::size_t distance = 0;
};

constexpr char WALL = '#';
constexpr char START = '@';
constexpr std::size_t MAX_GRID = 30;
constexpr std::size_t MAX_KEY_MASK = 64;

class Solution {
  using Grid = std::vector<std::string>;
  using VisitedGrid =
      std::array<std::array<std::array<bool, MAX_KEY_MASK>, MAX_GRID>,
                 MAX_GRID>;

  void reset() {
    total_keys = 0;
    dir_x = {{-1, 0, 1, 0}};
    dir_y = {{0, -1, 0, 1}};
  }

  auto find_start_point(Grid& grid) -> std::pair<std::size_t, std::size_t> {
    std::size_t val_x = std::string::npos;
    std::size_t val_y = std::string::npos;
    for (std::size_t i{0}; i < grid.size(); i++) {
      for (std::size_t j{0}; j < grid.at(i).size(); j++) {
        auto grid_char = grid.at(i).at(j);
        if (grid_char == START) {
          val_x = i;
          val_y = j;
        } else if (std::islower(static_cast<unsigned char>(grid_char)) != 0) {
          total_keys++;
        }
      }
    }
    return {val_x, val_y};
  }

  void iterate(Node& curr, std::queue<Node>& bfs, Grid& grid,
               VisitedGrid& visited) {
    for (std::size_t i{0}; i < dir_x.size(); i++) {
      auto next_row = static_cast<std::int32_t>(curr.pos_x) + dir_x.at(i);
      auto next_col = static_cast<std::int32_t>(curr.pos_y) + dir_y.at(i);

      if (next_row < 0 or next_col < 0) {
        continue;
      }
      auto row_idx = static_cast<std::size_t>(next_row);
      auto col_idx = static_cast<std::size_t>(next_col);

      if (row_idx >= grid.size() or col_idx >= grid.at(0).size()) {
        continue;
      }

      const char block = grid.at(row_idx).at(col_idx);

      if (block == WALL) {
        continue;
      }

      if (std::isupper(static_cast<unsigned char>(block)) != 0) {
        auto shift = static_cast<unsigned>(block - 'A');
        if ((curr.keys_found & (1U << shift)) == 0U) {
          continue;
        }
      }

      auto new_keys = curr.keys_found;
      if (std::islower(static_cast<unsigned char>(block)) != 0) {
        auto shift = static_cast<unsigned>(block - 'a');
        new_keys |= static_cast<std::uint8_t>(1U << shift);
      }

      if (visited.at(row_idx).at(col_idx).at(new_keys)) {
        continue;
      }
      visited.at(row_idx).at(col_idx).at(new_keys) = true;

      bfs.push(Node{.pos_x = row_idx,
                    .pos_y = col_idx,
                    .keys_found = new_keys,
                    .distance = curr.distance + 1});
    }
  }

 public:
  auto shortestPathAllKeys(Grid& grid) -> std::int32_t {
    reset();
    auto [start_x, start_y] = find_start_point(grid);

    auto all_keys = static_cast<std::uint8_t>((1U << total_keys) - 1U);

    VisitedGrid visited{};
    visited.at(start_x).at(start_y).at(0) = true;

    std::queue<Node> bfs;
    bfs.push(Node{
        .pos_x = start_x, .pos_y = start_y, .keys_found = 0, .distance = 0});

    while (!bfs.empty()) {
      auto val = bfs.front();
      bfs.pop();

      if (val.keys_found == all_keys) {
        return static_cast<std::int32_t>(val.distance);
      }

      iterate(val, bfs, grid, visited);
    }

    return -1;
  }

 private:
  std::size_t total_keys = 0;
  std::vector<std::int32_t> dir_x, dir_y;
};
