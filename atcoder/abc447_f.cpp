#include <algorithm>
#include <iostream>
#include <vector>

class Graph {
private:
  auto is_centipede(int node, int parent) -> bool {
    if (parent == -1)
      return graph[node].size() >= 2;
    return graph[node].size() >= 3;
  }

  auto dfs(int curr_node, int parent) -> int {
    if (centipede_len[curr_node] != -1)
      return centipede_len[curr_node];

    int max_len{0};
    if (is_centipede(curr_node, parent)) {
      max_len++;
      for (int nbr : graph[curr_node]) {
        if (nbr != parent) {
          max_len += dfs(nbr, curr_node);
        }
      }
      centipede_len[curr_node] = std::max(max_len, centipede_len[curr_node]);
    } else {
      centipede_len[curr_node] = 0; // always
      for (int nbr : graph[curr_node]) {
        if (nbr != parent) {
          dfs(nbr, curr_node);
        }
      }
    }
  }

public:
  Graph(int num_nodes) {
    graph.resize(num_nodes);
    centipede_len.resize(num_nodes, -1); // rooted at that node
  }

  void build() {
    for (int i = 0; i < graph.size() - 1; i++) {
      int u{}, v{};
      std::cin >> u >> v;
      graph[u - 1].push_back(v - 1);
      graph[v - 1].push_back(u - 1);
    }
  }

  void generate_centipede() {
    for (int i = 0; i < graph.size(); i++) {
      if (centipede_len[i] != -1)
        continue;
      centipede_len[i] = dfs(i, -1);
    }
  }

private:
  std::vector<std::vector<int>> graph;
  std::vector<int> centipede_len;
};

void work() {
  int num_nodes{};
  std::cin >> num_nodes;

  Graph g(num_nodes);
  g.build();
}

void solve() {
  int num_tests{};
  std::cin >> num_tests;

  while (num_tests--) {
    work();
  }
}