#include <iostream>

auto work() -> int {
  int a, b, x, y;
  std::cin >> a >> b >> x >> y;
  return (a + b) + (y - x) * (a / x);
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