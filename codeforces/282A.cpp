#include <cstddef>
#include <cstdint>
#include <iostream>

void solve() {
  std::uint16_t total_stmts{};
  std::cin >> total_stmts;

  std::int16_t current_val{0};

  for (std::uint16_t i{0}; i < total_stmts; i++) {
    char temp{};
    char operation{};

    std::cin >> temp >> operation >> temp;

    if (operation == '+') {
      current_val++;
    } else {
      current_val--;
    }
  }

  std::cout << current_val << '\n';
}