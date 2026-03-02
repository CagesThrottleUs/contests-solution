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

#include <algorithm>
#include <iostream>
#include <vector>

void work() {
  int num_items{};
  std::cin >> num_items;

  std::vector<int> items(num_items);
  for (int i = 0; i < num_items; i++) {
    std::cin >> items[i];
  }

  if (std::is_sorted(items.begin(), items.end())) {
    std::cout << items.size() << "\n";
  } else {
    std::cout << 1 << "\n";
  }
}

void solve() {
  int num_test_cases{};
  std::cin >> num_test_cases;

  while (num_test_cases > 0) {
    num_test_cases--;
    work();
  }
}
