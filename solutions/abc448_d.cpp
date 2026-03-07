/*
 *   MIT License
 *
 *   Copyright (c) 2026 CagesThrottleUs
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 */

#include <iostream>

#ifdef __GNUC__
#ifndef __clang__
#pragma GCC optimize("O3", "unroll-loops")
#endif
#endif

void speedup() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

// Forward declaration - to be implemented in problem file
void solve();

auto main() -> int {
    speedup();
    solve();
    return 0;
}

// Include the problem-specific implementation

#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <vector>

class Graph {
 private:
  void dfs(int node, std::vector<bool>& visited,
           std::unordered_map<int, int>& seen_node_vals,
           std::vector<bool>& result) const {
    visited[static_cast<std::size_t>(node)] = true;
    seen_node_vals[_node_values.at(static_cast<std::size_t>(node))]++;
    result[static_cast<std::size_t>(node)] =
        result[static_cast<std::size_t>(node)] ||
        seen_node_vals[_node_values.at(static_cast<std::size_t>(node))] > 1;

    for (int neighbor : _adj.at(static_cast<std::size_t>(node))) {
      if (!visited[static_cast<std::size_t>(neighbor)]) {
        result[static_cast<std::size_t>(neighbor)] =
            result[static_cast<std::size_t>(neighbor)] ||
            result[static_cast<std::size_t>(node)];
        dfs(neighbor, visited, seen_node_vals, result);
      }
    }

    seen_node_vals[_node_values.at(static_cast<std::size_t>(node))]--;
  }

 public:
  explicit Graph(int nodes) : _nodes(nodes) {
    _adj.resize(static_cast<std::size_t>(nodes), std::vector<int>());
    _node_values.resize(static_cast<std::size_t>(nodes), 0);

    for (int i{0}; i < _nodes; i++) {
      std::cin >> _node_values.at(static_cast<std::size_t>(i));
    }

    for (int i{0}; i < _nodes - 1; i++) {
      int _at{};
      int _to{};
      std::cin >> _at >> _to;
      _adj.at(static_cast<std::size_t>(_at - 1)).push_back(_to - 1);
      _adj.at(static_cast<std::size_t>(_to - 1)).push_back(_at - 1);
    }
  }

  [[nodiscard]] auto perform_op(int start) const -> std::vector<bool> {
    std::vector<bool> visited(static_cast<std::size_t>(_nodes), false);
    std::vector<bool> result(static_cast<std::size_t>(_nodes), false);
    std::unordered_map<int, int> seen_node_vals;

    dfs(start, visited, seen_node_vals, result);
    return result;
  }

 private:
  int _nodes;
  std::vector<std::vector<int>> _adj;
  std::vector<int> _node_values;
};

void solve() {
  int nodes{};
  std::cin >> nodes;

  Graph graph(nodes);
  auto result = graph.perform_op(0);

  for (const auto& val : result) {
    std::cout << (val ? "Yes\n" : "No\n");
  }
}
