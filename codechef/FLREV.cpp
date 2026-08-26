#include <cstdint>
#include <iostream>
#include <string>

void solve_test() {
  std::size_t _sz{};
  std::cin >> _sz;

  std::string str;
  std::cin >> str;

  std::size_t initial_beauty = 0;
  std::size_t transitions = 0;

  for (std::size_t i = 0; i + 1 < _sz; ++i) {
    if (str[i] == str[i + 1]) {
      initial_beauty++;
    } else {
      transitions++;
    }
  }

  std::size_t gain = 0;
  if (transitions >= 3) {
    gain = 2;
  } else if (transitions == 2) {
    gain = 1;
  } else {
    gain = 0;
  }

  std::cout << initial_beauty + gain << '\n';
}

void solve() noexcept {
  std::uint32_t tests{};
  std::cin >> tests;
  while (tests > 0) {
    tests--;
    solve_test();
  }
}