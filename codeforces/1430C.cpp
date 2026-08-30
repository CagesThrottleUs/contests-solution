#include <cstdint>
#include <iostream>

void test() noexcept {
  std::uint32_t total_size{};
  std::cin >> total_size;

  std::cout << "2\n";

  if (total_size == 2) {
    std::cout << "2 1\n";
    return;
  }

  std::cout << total_size << " " << total_size - 2 << "\n"
            << total_size - 1 << " " << total_size - 1 << "\n";

  total_size -= 1;

  while (total_size > 2) {
    std::cout << total_size << " " << total_size - 2 << "\n";
    total_size--;
  }
}

void solve() noexcept {
  std::uint16_t tests{};
  std::cin >> tests;

  while (tests > 0) {
    tests--;
    test();
  }
}