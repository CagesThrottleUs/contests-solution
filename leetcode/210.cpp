/*
 *   MIT License
 *
 *   Copyright (c) 2026 CagesThrottleUs
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <cstddef>
#include <queue>
#include <vector>

class Graph {
 private:
  void add_edge(std::size_t from, std::size_t _to) {
    neighbors[from].push_back(_to);
    in_degree[_to]++;
  }

 public:
  explicit Graph(std::size_t num_nodes, std::vector<std::vector<int>>& edges)
      : num_nodes(num_nodes) {
    neighbors.resize(num_nodes);
    in_degree.resize(num_nodes, 0);
    for (const auto& edge : edges) {
      add_edge(static_cast<std::size_t>(edge[1]),
               static_cast<std::size_t>(edge[0]));
    }
  }

  auto topological_sort() -> std::vector<int> {
    std::queue<std::size_t> process;
    for (std::size_t i{0}; i < num_nodes; i++) {
      if (in_degree[i] == 0) {
        process.push(i);
      }
    }

    std::vector<int> result;
    result.reserve(num_nodes);

    while (!process.empty()) {
      std::size_t node = process.front();
      process.pop();
      result.push_back(static_cast<int>(node));
      for (const auto& _to : neighbors[node]) {
        in_degree[_to]--;
        if (in_degree[_to] == 0) {
          process.push(_to);
        }
      }
    }

    if (result.size() != num_nodes) {
      result.clear();
    }

    return result;
  }

 private:
  std::size_t num_nodes;
  std::vector<std::vector<std::size_t>> neighbors;
  std::vector<int> in_degree;
};

class Solution {
 public:
  static auto findOrder(int numCourses,
                        std::vector<std::vector<int>>& prerequisites)
      -> std::vector<int> {
    Graph graph(static_cast<std::size_t>(numCourses), prerequisites);
    return graph.topological_sort();
  }
};