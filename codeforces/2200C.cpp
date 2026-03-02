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