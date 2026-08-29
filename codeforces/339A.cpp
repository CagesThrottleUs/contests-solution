#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

void solve() noexcept {
  std::vector<char> res{};
  constexpr std::size_t MAX_SIZE = 100;
  res.reserve(MAX_SIZE + 1);

  char _ch{};

  while (std::cin >> _ch) {
    if (_ch == '+') {
      continue;
    }
    res.emplace_back(_ch);
  }

  std::ranges::sort(res);

  std::cout << res.front();
  for (std::size_t i{1}; i < res.size(); i++) {
    std::cout << "+" << res.at(i);
  }
  std::cout << "\n";
}