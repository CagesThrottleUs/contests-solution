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