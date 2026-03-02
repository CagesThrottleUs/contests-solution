#include <iostream>

auto work() -> bool {
  long long n{}, k{};
  std::cin >> n >> k;

  if (n % 2 == 0) {
    return true;
  }

  auto rem = n % k;
  if ((rem & 1) == 1 and (k & 1) == 0) {
    return false;
  }
  return true;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    auto sol = work();
    std::cout << (sol ? "YES" : "NO") << "\n";
  }
}