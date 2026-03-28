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
#include <vector>

class Graph {
  std::size_t n;  // num nodes
  std::vector<std::vector<std::size_t>> neighbors;

 public:
  Graph(std::vector<std::vector<int>>& edges, std::size_t n) : n(n) {
    neighbors.resize(n);
    for (const auto& edge : edges) {
      add_edge(static_cast<std::size_t>(edge[0]),
               static_cast<std::size_t>(edge[1]));
    }
  }

 private:
  void add_edge(std::size_t from, std::size_t _to) {
    neighbors[from].push_back(_to);
  }

 public:
  auto has_cycle() -> bool {
    std::vector<bool> on_stack(n, false);
    std::vector<bool> visited(n, false);
    for (std::size_t i{0}; i < n; i++) {
      if (!visited[i] && dfs(i, visited, on_stack)) {
        return true;
      }
    }
    return false;
  }

 private:
  auto dfs(std::size_t _at, std::vector<bool>& visited,
           std::vector<bool>& on_stack) -> bool {
    visited[_at] = true;
    on_stack[_at] = true;
    for (const auto& _to : neighbors[_at]) {
      if (on_stack[_to]) {
        return true;
      }
      if (!visited[_to] && dfs(_to, visited, on_stack)) {
        return true;
      }
    }
    on_stack[_at] = false;
    return false;
  }
};

class Solution {
 public:
  auto canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites)
      -> bool {
    Graph graph(prerequisites, static_cast<std::size_t>(numCourses));
    return !graph.has_cycle();
  }
};