#include <cctype>
#include <iostream>
#include <string_view>

namespace constants {

constexpr std::string_view VOWELS = "aeiouy";

constexpr auto is_vowel(char _ch) noexcept -> bool {
  return VOWELS.contains(_ch);
}

}  // namespace constants

void solve() noexcept {
  char _ch{};
  while (std::cin >> _ch) {
    _ch = static_cast<char>(std::tolower(_ch));
    if (constants::is_vowel(_ch)) {
      continue;
    }
    std::cout << "." << _ch;
  }
  std::cout << "\n";
}