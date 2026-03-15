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
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
  std::vector<int> parent, rnk, sz;

  // NOLINTNEXTLINE(misc-no-recursion)
  auto find(int node) -> int {
    if (parent[static_cast<std::size_t>(node)] != node) {
      parent[static_cast<std::size_t>(node)] =
          find(parent[static_cast<std::size_t>(node)]);
    }
    return parent[static_cast<std::size_t>(node)];
  }

  void unite(int root_x, int root_y) {
    root_x = find(root_x);
    root_y = find(root_y);
    if (root_x == root_y) {
      return;
    }
    if (rnk[static_cast<std::size_t>(root_x)] <
        rnk[static_cast<std::size_t>(root_y)]) {
      std::swap(root_x, root_y);
    }
    parent[static_cast<std::size_t>(root_y)] = root_x;
    sz[static_cast<std::size_t>(root_x)] +=
        sz[static_cast<std::size_t>(root_y)];
    if (rnk[static_cast<std::size_t>(root_x)] ==
        rnk[static_cast<std::size_t>(root_y)]) {
      rnk[static_cast<std::size_t>(root_x)]++;
    }
  }

 public:
  auto maxActivated(std::vector<std::vector<int>>& points) -> int {
    auto total_points = points.size();
    parent.resize(total_points);
    rnk.assign(total_points, 0);
    sz.assign(total_points, 1);
    for (int i = 0; i < static_cast<int>(total_points); i++) {
      parent[static_cast<std::size_t>(i)] = i;
    }

    std::unordered_map<int, std::vector<int>> byX;
    std::unordered_map<int, std::vector<int>> byY;
    for (int i = 0; i < static_cast<int>(total_points); i++) {
      byX[points[static_cast<std::size_t>(i)][0]].push_back(i);
      byY[points[static_cast<std::size_t>(i)][1]].push_back(i);
    }

    // Union all points sharing x or y
    for (auto& [first, grp] : byX) {
      for (int i = 1; i < static_cast<int>(grp.size()); i++) {
        unite(grp[0], grp[static_cast<std::size_t>(i)]);
      }
    }
    for (auto& [first, grp] : byY) {
      for (int i = 1; i < static_cast<int>(grp.size()); i++) {
        unite(grp[0], grp[static_cast<std::size_t>(i)]);
      }
    }

    // After DSU: each x-value collapses to one root, same for y
    // rootOfX[x] = the single root for all points with that x
    std::unordered_map<int, int> rootOfX;
    std::unordered_map<int, int> rootOfY;
    for (auto& [coord_x, grp] : byX) {
      rootOfX[coord_x] = find(grp[0]);
    }
    for (auto& [coord_y, grp] : byY) {
      rootOfY[coord_y] = find(grp[0]);
    }

    // Case 2 & 3: new point aligns with only one existing axis
    // Best is just 1 + largest cluster size
    int maxCluster = 0;
    for (int i = 0; i < static_cast<int>(total_points); i++) {
      maxCluster = std::max(maxCluster, sz[static_cast<std::size_t>(find(i))]);
    }
    int best = 1 + maxCluster;

    // Case 1: new point (existing x, existing y) bridges two clusters
    // For each x-root rx, we want the largest y-root ry where ry != rx
    // Precompute top-2 cluster sizes among all y-roots
    // (top-2 because if best y-root == rx, we fall back to second best)

    // Collect all y-roots and their sizes
    std::unordered_set<int> yRootSet;
    for (auto& [coord_y, root_y] : rootOfY) {
      yRootSet.insert(root_y);
    }

    // top2: (size, root) among y-roots
    std::pair<int, int> top1 = {-1, -1};
    std::pair<int, int> top2 = {-1, -1};
    for (int root_y : yRootSet) {
      if (sz[static_cast<std::size_t>(root_y)] > top1.first) {
        top2 = top1;
        top1 = {sz[static_cast<std::size_t>(root_y)], root_y};
      } else if (sz[static_cast<std::size_t>(root_y)] > top2.first) {
        top2 = {sz[static_cast<std::size_t>(root_y)], root_y};
      }
    }

    // For each existing x, try bridging with best available y-root
    for (auto& [coord_x, root_x] : rootOfX) {
      // Check if (x, y) already exists for some y —
      // we need a y that gives a root different from rx
      // and (x, y) must not already be in points
      // For now get best y-root != rx
      int yBestSize = (top1.second != root_x) ? top1.first : top2.first;
      if (yBestSize < 0) {
        continue;  // no valid y-root
      }

      // But we also need to verify the candidate (x, y) doesn't already exist.
      // Since any existing (x, ?) would have rootOfX[x] = rx already merged,
      // a y giving ry != rx means that y is NOT in byX[x] → (x,y) is safe.
      best =
          std::max(best, 1 + sz[static_cast<std::size_t>(root_x)] + yBestSize);
    }

    return best;
  }
};