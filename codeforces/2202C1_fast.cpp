#include <iostream>

std::vector<int> reduce(const std::vector<int> &a) {
  std::vector<int> reduced;
  for (int i = 0; i < a.size(); i++) {
    if (i == 0 || a[i] != a[i - 1] + 1) {
      reduced.push_back(a[i]);
    }
  }
  return reduced;
}

void work() {
  int n{};
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  while (true) {
    auto reduced = reduce(a);
    if (reduced.size() == a.size()) {
      break;
    }
    a = reduced;
  }
  std::cout << a.size() << "\n";
}

void solve() {
  int num_test_case{};
  std::cin >> num_test_case;
  while (num_test_case > 0) {
    num_test_case--;
    work();
  }
}