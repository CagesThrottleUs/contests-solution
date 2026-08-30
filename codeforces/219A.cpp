#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>

namespace constants {

constexpr std::size_t ALPHABET_SIZE = 26;

} // namespace constants

void solve() noexcept {
  std::uint16_t modulo{};
  std::cin >> modulo;

  std::array<std::size_t, constants::ALPHABET_SIZE> freq{};

  char _ch{};
  while (std::cin >> _ch) {
    freq.at(static_cast<std::size_t>(_ch - 'a'))++;
  }

  for (std::size_t i{0}; i < freq.size(); i++) {
    const auto& val = freq.at(i);
    if (val % modulo != 0) {
      std::cout << "-1\n";
      return;
    }
    freq.at(i) = freq.at(i) / modulo;
  }

  for (std::uint16_t rep_cnt{0}; rep_cnt < modulo; rep_cnt++) {
    for (std::size_t i{0}; i < freq.size(); i++) {
      if (freq.at(i) == 0) {
        continue;
      }
      char _ch = static_cast<char>('a' + i);
      std::cout << std::string(freq.at(i), _ch);
    }
  }

  std::cout << "\n";
}