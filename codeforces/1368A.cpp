#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>

void solve_test() noexcept {
  std::uint64_t smaller{};
  std::uint64_t larger{};
  std::uint64_t limit{};

  std::cin >> smaller >> larger >> limit;

  auto fix = [&smaller, &larger]() -> void {
    auto temp_s = std::min(smaller, larger);
    auto temp_l = std::max(smaller, larger);

    smaller = temp_s;
    larger = temp_l;
  };

  fix();

  std::size_t total_ops{0};

  while (larger <= limit) {
    total_ops++;
    smaller += larger;
    fix();
  }

  std::cout << total_ops << "\n";
}

void solve() noexcept {
  std::uint16_t tests{};
  std::cin >> tests;

  while (tests > 0) {
    tests--;
    solve_test();
  }
}