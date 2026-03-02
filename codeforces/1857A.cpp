#include <iostream>

auto work() -> int {
  int n{};
  std::cin >> n;

  int sum{0};
  for (int i{0}; i < n; i++) {
    int input{};
    std::cin >> input;
    sum += input;
  }
  return sum;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    auto sum = work();

    if ((sum & 1) == 1) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
    }
  }
}