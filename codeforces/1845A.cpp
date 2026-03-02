#include <iostream>

void print(int n, int times) {
  if (times == 0) return;
  std::cout << n;
  for (int i{0}; i < times - 1; i++) {
    std::cout << " " << n;
  }
}

void work() {
  int n{}, k{}, x{};
  std::cin >> n >> k >> x;

  if ((k == 1 && x == 1) || (k == 2 && x == 1 && (n & 1))) {
    std::cout << "NO\n";
    return;
  }

  std::cout << "YES\n";
  if (x == 1) {
    int c2 = (n / 2) - (n & 1), c3 = (n & 1);
    std::cout << c2 + c3 << "\n";
    print(2, c2);
    std::cout << " ";
    print(3, c3);
  } else {
    std::cout << n << "\n";
    print(1, n);
  }
  std::cout << "\n";
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    work();
  }
}