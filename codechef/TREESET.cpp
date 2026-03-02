#include <iostream>
#include <vector>

constexpr int MODULO = 998244353;

struct Node {
  std::vector<int> nbrs{};
  bool visited{false};
};

void dfs(int node, std::vector<Node> &graph,
         long long &num_nodes_in_component) {
  graph[node].visited = true;
  num_nodes_in_component++;
  num_nodes_in_component %= MODULO;
  for (int nbr : graph[node].nbrs) {
    if (!graph[nbr].visited) {
      dfs(nbr, graph, num_nodes_in_component);
    }
  }
}

auto binpow(long long a, long long b, long long m) -> long long {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}

auto count_sol(int num_nodes_in_component) -> long long {
  // all subsets that have at least two nodes
  auto total_subsets = binpow(2, num_nodes_in_component, MODULO);
  return (total_subsets - num_nodes_in_component - 1) % MODULO;
}

auto work() -> int {
  int num_nodes{};
  std::cin >> num_nodes;

  std::vector<Node> graph(num_nodes);

  for (int i = 0; i < num_nodes - 1; i++) {
    int u{}, v{};
    std::cin >> u >> v;
    graph[u - 1].nbrs.push_back(v - 1);
    graph[v - 1].nbrs.push_back(u - 1);
  }

  int sol = 0;

  // num connected components and total number of nodes in each component
  for (int i = 0; i < num_nodes; i++) {
    if (!graph[i].visited) {
      long long num_nodes_in_component = 0;
      dfs(i, graph, num_nodes_in_component);
      std::cout << "num_nodes_in_component: " << num_nodes_in_component << "\n";
      sol += count_sol(num_nodes_in_component);
      sol %= MODULO;
    }
  }

  return sol;
}

void solve() {
  int num_test_cases{};
  std::cin >> num_test_cases;

  while (num_test_cases > 0) {
    num_test_cases--;
    auto sol = work();
    std::cout << sol << "\n";
  }
}