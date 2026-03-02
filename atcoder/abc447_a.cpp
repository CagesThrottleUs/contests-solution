#include <iostream>

void solve() {
  int n, m;
  std::cin >> n >> m;

  int allowed_upper = n - (n / 2);

  if (m <= allowed_upper) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}