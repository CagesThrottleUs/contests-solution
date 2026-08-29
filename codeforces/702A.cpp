#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
void solve() noexcept {
  std::size_t total_nums{};
  std::cin >> total_nums;

  std::uint32_t last{0};
  std::size_t curr_size{0};
  std::size_t max_size{0};

  for (std::size_t i{0}; i < total_nums; i++) {
    std::uint32_t num{};
    std::cin >> num;

    if (num > last) {
      curr_size++;
    } else {
      max_size = std::max(max_size, curr_size);
      curr_size = 1;
    }

    last = num;
  }

  max_size = std::max(max_size, curr_size);

  std::cout << max_size << "\n";
}