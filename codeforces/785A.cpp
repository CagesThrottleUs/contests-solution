#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>

void solve() noexcept {
  const std::unordered_map<char, std::uint32_t> POLY_TO_FACES = {
      {'T', 4}, {'C', 6}, {'O', 8}, {'D', 12}, {'I', 20},
  };
  // const std::size_t MAX_SIZE = 15;

  std::uint32_t faces{0};

  std::uint32_t total_polys{0};
  std::cin >> total_polys;

  std::string poly;
  while (total_polys > 0) {
    total_polys--;
    // poly.reserve(MAX_SIZE);
    std::cin >> poly;
    faces += POLY_TO_FACES.at(poly.front());
  }

  std::cout << faces << '\n';
}