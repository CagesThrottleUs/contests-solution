#include <iostream>

void work() {
  int x_coord{}, y_coord{};
  std::cin >> x_coord >> y_coord;

  auto diff = x_coord - 2 * y_coord;

  if (diff < 0) {
    std::cout << "NO\n";
    return;
  }

  if (diff % 3 != 0) {
    std::cout << "NO\n";
    return;
  }

  diff /= 3;

  if (y_coord >= -(diff / 2)) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
}

void solve() {
  int num_test_case{};
  std::cin >> num_test_case;

  while (num_test_case > 0) {
    num_test_case--;
    work();
  }
}