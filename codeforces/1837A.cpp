#include <iostream>

void work() {
  int x{}, k{};
  std::cin >> x >> k;

  int rem = (x % k);

  if (rem == 0) {
    std::cout << "2\n";
    std::cout << x - 1 << " " << 1 << "\n";
  } else {
    std::cout << "1\n";
    std::cout << x << "\n";
  }
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    work();
  }
}