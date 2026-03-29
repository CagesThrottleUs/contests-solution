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

#include <numeric>
#include <utility>
#include <vector>

struct DSU {
  std::vector<int> parent, rnk, dist;

  explicit DSU(int nodes)
      : parent(static_cast<std::size_t>(nodes)),
        rnk(static_cast<std::size_t>(nodes), 0),
        dist(static_cast<std::size_t>(nodes), 0) {
    std::ranges::iota(parent, 0);
  }

  auto find(int node) -> int {
    if (parent[static_cast<std::size_t>(node)] != node) {
      int root = find(parent[static_cast<std::size_t>(node)]);
      // NOLINTNEXTLINE(hicpp-signed-bitwise)
      dist[static_cast<std::size_t>(node)] ^= dist[static_cast<std::size_t>(
          parent[static_cast<std::size_t>(node)])];
      parent[static_cast<std::size_t>(node)] = root;
    }
    return parent[static_cast<std::size_t>(node)];
  }

  // returns true if edge is accepted
  // NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
  auto unite(int from, int _to, int weight) -> bool {
    int r_from = find(from);
    int r_to = find(_to);
    int dist_from = dist[static_cast<std::size_t>(from)];
    int dist_to = dist[static_cast<std::size_t>(_to)];

    if (r_from == r_to) {
      // NOLINTNEXTLINE(hicpp-signed-bitwise)
      return (dist_from ^ dist_to ^ weight) == 0;
    }

    if (rnk[static_cast<std::size_t>(r_from)] <
        rnk[static_cast<std::size_t>(r_to)]) {
      std::swap(r_from, r_to);
      std::swap(dist_from, dist_to);
    }
    parent[static_cast<std::size_t>(r_to)] = r_from;
    // NOLINTNEXTLINE(hicpp-signed-bitwise)
    dist[static_cast<std::size_t>(r_to)] = dist_from ^ dist_to ^ weight;
    if (rnk[static_cast<std::size_t>(r_from)] ==
        rnk[static_cast<std::size_t>(r_to)]) {
      rnk[static_cast<std::size_t>(r_from)]++;
    }
    return true;
  }
};

class Solution {
 public:
  auto numberOfEdgesAdded(int n, std::vector<std::vector<int>>& edges) -> int {
    DSU dsu(n);
    int ans = 0;
    for (const auto& edge : edges) {
      if (dsu.unite(edge[0], edge[1], edge[2])) {
        ans++;
      }
    }
    return ans;
  }
};