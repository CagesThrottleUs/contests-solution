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
#include <vector>

void print(const std::vector<int> &arr) {
  if (arr.empty()) {
    return;
  }
  std::cout << arr.front();
  for (int i = 1; i < arr.size(); i++) {
    std::cout << " " << arr[i];
  }
  std::cout << "\n";
}

auto work() -> std::vector<int> {
  int n{};
  std::cin >> n;
  std::vector<int> arr;
  bool first = true;

  for (int i = 0; i < n; i++) {
    int temp{};
    std::cin >> temp;

    if (first) {
      first = false;
      arr.push_back(temp);
    } else {
      if (temp >= arr.back()) {
        arr.push_back(temp);
      } else {
        arr.push_back(temp);
        arr.push_back(temp);
      }
    }
  }

  return arr;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    auto arr = work();
    std::cout << arr.size() << "\n";
    print(arr);
  }
}
