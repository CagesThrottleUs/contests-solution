#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

auto can_divide(const std::vector<int> &arr) -> bool {
  auto [first, last] = std::equal_range(arr.begin(), arr.end(), arr.front());
  return last != arr.end();
}

auto get_b_and_c(const std::vector<int> &arr)
    -> std::pair<std::vector<int>, std::vector<int>> {
  auto [first, last] = std::equal_range(arr.begin(), arr.end(), arr.back());
  auto c = std::vector<int>(first, last);
  auto b = std::vector<int>(arr.begin(), first);
  return {b, c};
}

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

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    int n{};
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());

    if (!can_divide(arr)) {
      std::cout << -1 << "\n";
    } else {
      auto [b, c] = get_b_and_c(arr);
      std::cout << b.size() << " " << c.size() << "\n";
      print(b);
      print(c);
    }
  }
}