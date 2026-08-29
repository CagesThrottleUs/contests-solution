#include <bitset>
#include <cstddef>
#include <iostream>
#include <string>

void solve() noexcept {
  constexpr std::size_t NUM_CHARS = 26;
  std::bitset<NUM_CHARS> alphabet{0U};

  std::string str;
  std::cin >> str;

  for (const auto& _ch : str) {
    alphabet.set(static_cast<std::size_t>(_ch - 'a'));
  }

  auto count = alphabet.count();

  if ((count & 1ULL) == 1) {
    std::cout << "IGNORE HIM!\n";
  } else {
    std::cout << "CHAT WITH HER!\n";
  }
}