#include <cctype>
#include <iostream>
#include <string>
void solve() noexcept {
  std::string str{};
  std::cin >> str;

  str.at(0) = static_cast<char>(std::toupper(str.front()));

  std::cout << str << "\n";
}