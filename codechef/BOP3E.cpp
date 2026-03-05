/*
 *   Copyright (c) 2026 CagesThrottleUs
 *   All rights reserved.
 */
#include <algorithm>
#include <iostream>

void print_sol() {
  int n{};
  std::cin >> n;

  std::cout << 0;
  int temp{};
  std::cin >> temp;

  int curr_balloons{1};

  for (int i{1}; i < n; i++) {
    std::cin >> temp;
    auto i_balloons = std::min(temp, curr_balloons);
    std::cout << " " << i_balloons;
    curr_balloons += (i_balloons != temp);
  }
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    print_sol();
    std::cout << "\n";
  }
}