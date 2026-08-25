
#include <cstdint>
#include <iostream>

void solve() noexcept {
  std::uint16_t num_people{};
  std::cin >> num_people;

  while (num_people > 0) {
    num_people--;
    bool val{false};
    std::cin >> val;
    if (val) {
      std::cout << "HARD\n";
      return;
    }
  }

  std::cout << "EASY\n";
}