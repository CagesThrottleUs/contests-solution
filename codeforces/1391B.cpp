#include <cstddef>
#include <iostream>

void solve_test() noexcept {
  std::size_t rows{};
  std::size_t cols{};
  std::cin >> rows >> cols;

  std::size_t count{0};

  for (std::size_t row{1}; row <= rows; row++) {
    for (std::size_t col{1}; col <= cols; col++) {
      char _ch{};
      std::cin >> _ch;

      if (row == rows and col == cols) {
        continue;
      }

      if (row == rows) {
        [[unlikely]] count += static_cast<std::size_t>(_ch == 'D');
      }
      if (col == cols) {
        [[unlikely]] count += static_cast<std::size_t>(_ch == 'R');
      }
    }
  }

  std::cout << count << "\n";
}

void solve() noexcept {
  std::size_t tests{};
  std::cin >> tests;

  while (tests > 0) {
    tests--;
    solve_test();
  }
}