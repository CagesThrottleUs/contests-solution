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

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <stack>
#include <vector>

void dfs(std::size_t start, std::vector<bool>& visited,
         const std::vector<std::vector<std::size_t>>& adj_list) {
  visited.at(start) = true;
  std::stack<std::pair<std::size_t, std::size_t>> stk;
  stk.emplace(start, 0UZ);
  while (!stk.empty()) {
    auto& [node, idx] = stk.top();
    if (idx == adj_list.at(node).size()) {
      stk.pop();
    } else {
      const auto next = adj_list.at(node).at(idx);
      ++idx;
      if (!visited.at(next)) {
        visited.at(next) = true;
        stk.emplace(next, 0UZ);
      }
    }
  }
}

void solve() {
  std::size_t num_nodes{};
  std::size_t num_edges{};

  std::cin >> num_nodes >> num_edges;

  std::vector<std::vector<std::size_t>> adj_list(num_nodes + 1);

  for (std::size_t i{0}; i < num_edges; i++) {
    std::size_t from{};
    std::size_t _to{};
    std::cin >> from >> _to;
    adj_list.at(from).push_back(_to);
  }

  std::vector<bool> visited(num_nodes + 1, false);

  dfs(1, visited, adj_list);

  auto count =
      std::ranges::count_if(visited, [](bool val) -> bool { return val; });

  std::cout << count << "\n";
}