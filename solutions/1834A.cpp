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

auto count_ops() -> int {
  int n{};
  std::cin >> n;

  int cnt_1{0};
  int cnt_neg_1{0};

  for (int i{0}; i < n; i++) {
    int input{};
    std::cin >> input;
    if (input == 1) {
      cnt_1++;
    } else if (input == -1) {
      cnt_neg_1++;
    }
  }

//   std::cout << "cnt_1: " << cnt_1 << "\n";
//   std::cout << "cnt_neg_1: " << cnt_neg_1 << "\n";

  int ops{0};

  // cond-1
  int desired_1 = (n / 2) + (n & 1);
  int desired_neg_1 = n - desired_1;

//   std::cout << "desired_1: " << desired_1 << "\n";
//   std::cout << "desired_neg_1: " << desired_neg_1 << "\n";

  if (!((cnt_1 >= desired_1) and (cnt_neg_1 <= desired_neg_1))) {
    ops += desired_1 - cnt_1;
    cnt_1 = desired_1;
    cnt_neg_1 = desired_neg_1;
  }

//   std::cout << "ops after cond-1: " << ops << "\n";

  // cond-2
  if ((cnt_neg_1 & 1) == 1) {
    ops += 1;
  }

//   std::cout << "ops after cond-2: " << ops << "\n";

  return ops;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    auto sol = count_ops();
    std::cout << sol << "\n";
  }
}
