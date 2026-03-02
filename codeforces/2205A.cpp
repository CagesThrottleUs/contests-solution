#include <cstddef>
#include <iostream>
#include <vector>

void solve() {

  int test_cases{};
  std::cin >> test_cases;
  while (test_cases--) {
    std::size_t num_eles{};
    std::cin >> num_eles;
    std::vector<int> eles(num_eles);
    std::size_t max_idx{0};
    for (std::size_t i = 0; i < num_eles; i++) {
      std::cin >> eles[i];
      if (eles[i] > eles[max_idx]) {
        max_idx = i;
      }
    }
    std::cout << eles[max_idx];
    for (std::size_t i = 0; i < num_eles; i++) {
      if (i != max_idx) {
        std::cout << " " << eles[i];
      }
    }
    std::cout << "\n";
  }
}