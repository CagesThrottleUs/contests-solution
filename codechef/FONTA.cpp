#include <iostream>
#include <string>

void solve() {
  std::string str;
  std::cin >> str;
  if (str.ends_with("nta")) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
}