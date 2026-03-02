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
#include <stack>

auto work() -> bool {
  int num_chars{};
  std::cin >> num_chars;

  std::stack<char> stk;
  for (int i = 0; i < num_chars; i++) {
    char c{};
    std::cin >> c;
    if (!stk.empty() && stk.top() == c) {
      stk.pop();
    } else {
      stk.push(c);
    }
  }

  return stk.empty();
}

void solve() {
  int num_test_cases{};
  std::cin >> num_test_cases;

  while (num_test_cases > 0) {
    num_test_cases--;
    auto sol = work();
    if (sol) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}
