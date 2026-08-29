#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

void solve_test() noexcept {
  std::vector<std::pair<std::size_t, std::size_t>> one_blocks;

  std::string str;
  std::cin >> str;

  std::size_t size{0};

  for (std::size_t i{0}; i < str.size(); i++) {
    const auto& _ch = str[i];
    if (_ch == '0' and size > 0) {
      one_blocks.emplace_back(i - size, i - 1);
      size = 0;
    } else if (_ch == '0') {
      continue;
    } else {
      size++;
    }
  }

  if (size > 0) {
    one_blocks.emplace_back(str.size() - size, str.size() - 1);
  }

  std::size_t total_count{0};

  for (std::size_t i{1}; i < one_blocks.size(); i++) {
    total_count += one_blocks[i].first - one_blocks[i - 1].second - 1;
  }

  std::cout << total_count << "\n";
}

void solve() noexcept {
  std::uint16_t tests{};
  std::cin >> tests;

  while (tests > 0) {
    tests--;
    solve_test();
  }
}