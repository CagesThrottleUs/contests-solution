#include <iostream>

auto work() -> int {
    int n, s;
    std::cin >> n >> s;

    if (s <= 5 * n) {
        // We can achieve the sum using only faces 1-5 on every die.
        // Therefore, every die still has its '6' face available.
        return 6 * n;
    } else {
        // We are forced to use some 6s to reach the sum S.
        // Every 6 we use reduces that die's max score from 6 to 5.
        int num_sixes_needed = s - 5 * n;
        return (num_sixes_needed * 5) + ((n - num_sixes_needed) * 6);
        // Equivalently: return 11 * n - s;
    }
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