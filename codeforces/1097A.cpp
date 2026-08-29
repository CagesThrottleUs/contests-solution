#include <cstddef>
#include <iostream>

void solve() noexcept {
  char req_rank{};
  char req_suit{};
  std::cin >> req_rank >> req_suit;

  constexpr std::size_t LOOP_SIZE = 5;

  for (std::size_t i{0}; i < LOOP_SIZE; i++) {
    char rank{};
    char suit{};
    std::cin >> rank >> suit;

    if (rank == req_rank || suit == req_suit) {
      std::cout << "YES\n";
      return;
    }
  }

  std::cout << "NO\n";
}