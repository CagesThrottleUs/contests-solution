#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>

void solve() noexcept {
  std::size_t stops{};
  std::cin >> stops;

  std::uint64_t capacity{0};
  std::uint64_t max_cap{0};

  for (std::size_t i{0}; i < stops; i++) {
    std::uint64_t exit_size{};
    std::uint64_t entry_size{};
    std::cin >> exit_size >> entry_size;

    capacity = capacity - exit_size + entry_size;
    max_cap = std::max(max_cap, capacity);
  }

  std::cout << max_cap << '\n';
}