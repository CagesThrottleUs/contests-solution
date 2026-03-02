#include <iostream>

#ifdef __GNUC__
#ifndef __clang__
#pragma GCC optimize("O3", "unroll-loops")
#endif
#endif

void speedup() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

// Forward declaration - to be implemented in problem file
void solve();

auto main() -> int {
    speedup();
    solve();
    return 0;
}

// Include the problem-specific implementation

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
