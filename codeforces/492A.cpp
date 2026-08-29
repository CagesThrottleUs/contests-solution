#include <cstddef>
#include <iostream>

void solve() noexcept {
  std::size_t max_cubes{};
  std::cin >> max_cubes;

  std::size_t max_height{0};

  constexpr std::size_t SIX = 6;

  auto rhs = SIX * max_cubes;

  for (std::size_t height{1}; height <= max_cubes; height++) {
    auto prod = height * (height + 1) * (height + 2);
    if (prod > rhs) {
      break;
    }
    max_height = height;
  }

  std::cout << max_height << "\n";
}