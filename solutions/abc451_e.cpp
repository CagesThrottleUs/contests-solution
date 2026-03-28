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

#include <iostream>

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3", "unroll-loops")
#elif defined(__clang__)
#pragma clang optimize on
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

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using DistMat = std::vector<std::vector<int>>;
using AdjList = std::vector<std::vector<std::pair<std::size_t, int>>>;

// Build the unique candidate tree by greedily assigning each vertex its
// deepest ancestor on the root-to-vertex path.
auto build_tree(const DistMat& distances, std::size_t num_verts) -> AdjList {
  std::vector<std::size_t> order(num_verts);
  std::ranges::iota(order, 0UZ);
  std::ranges::sort(order, [&](std::size_t lhs, std::size_t rhs) -> bool {
    return distances[0][lhs] < distances[0][rhs];
  });

  AdjList adj(num_verts);
  for (std::size_t idx = 1; idx < num_verts; idx++) {
    std::size_t vtx = order[idx];
    std::size_t par = order[0];  // root is always a valid ancestor (depth 0)
    for (std::size_t jdx = 1; jdx < idx; jdx++) {
      std::size_t cand = order[jdx];
      if (distances[0][cand] + distances[cand][vtx] == distances[0][vtx] &&
          distances[0][cand] > distances[0][par]) {
        par = cand;
      }
    }
    adj[vtx].emplace_back(par, distances[vtx][par]);
    adj[par].emplace_back(vtx, distances[vtx][par]);
  }
  return adj;
}

// Verify the candidate tree reproduces every pairwise distance in the matrix.
auto verify_distances(const AdjList& adj, const DistMat& distances,
                      std::size_t num_verts) -> bool {
  for (std::size_t src = 0; src < num_verts; src++) {
    std::vector<int> bfs_dist(num_verts, -1);
    bfs_dist[src] = 0;
    std::queue<std::size_t> bfs_queue;
    bfs_queue.push(src);
    while (!bfs_queue.empty()) {
      std::size_t cur = bfs_queue.front();
      bfs_queue.pop();
      for (auto [nbr, weight] : adj[cur]) {
        if (bfs_dist[nbr] == -1) {
          bfs_dist[nbr] = bfs_dist[cur] + weight;
          bfs_queue.push(nbr);
        }
      }
    }
    for (std::size_t dst = 0; dst < num_verts; dst++) {
      if (dst != src && bfs_dist[dst] != distances[src][dst]) {
        return false;
      }
    }
  }
  return true;
}

void solve() {
  int num_verts_raw{};
  std::cin >> num_verts_raw;
  const auto num_verts = static_cast<std::size_t>(num_verts_raw);

  DistMat distances(num_verts, std::vector<int>(num_verts, 0));
  for (std::size_t row = 0; row < num_verts - 1; row++) {
    for (std::size_t col = row + 1; col < num_verts; col++) {
      std::cin >> distances[row][col];
      distances[col][row] = distances[row][col];
    }
  }

  auto adj = build_tree(distances, num_verts);
  std::cout << (verify_distances(adj, distances, num_verts) ? "Yes" : "No")
            << "\n";
}
