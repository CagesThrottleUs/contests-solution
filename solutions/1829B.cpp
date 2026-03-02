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

auto len_subarr() -> int {
  int n{};
  std::cin >> n;

  int longest_len{0};
  int cur_len{0};

  for (int i{0}; i < n; i++) {
    int num{};
    std::cin >> num;
    if (num == 0) {
      cur_len++;
      longest_len = std::max(longest_len, cur_len);
    } else {
      cur_len = 0;
    }
  }

  return longest_len;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    auto sol = len_subarr();
    std::cout << sol << "\n";
  }
}
