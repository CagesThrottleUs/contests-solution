#include <iostream>

void find_permutation() {
  int n{};
  std::cin >> n;

  int temp{};
  bool first{true};

  for (int i{0}; i < n; i++) {
    std::cin >> temp;
    if (first) {
      first = false;
      std::cout << n - temp + 1;
    } else {
      [[likely]] std::cout << " " << n - temp + 1;
    }
  }
  std::cout << "\n";
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    find_permutation();
  }
}