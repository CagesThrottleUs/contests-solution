#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits>

void solve() {
  int n{};
  std::cin >> n;

  int min_op = std::numeric_limits<int>::max();
  for (int i = 0; i < n; i++) {
    int a{};
    std::cin >> a;
    min_op = std::min(min_op, std::abs(a));
  }
  std::cout << min_op << "\n";
}