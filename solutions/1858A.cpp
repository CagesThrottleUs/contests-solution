#include <iostream>

#ifdef __GNUC__
#ifndef __clang__
#pragma GCC optimize("O3", "unroll-loops")
#endif
#endif

void speedup() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

// Forward declaration - to be implemented in problem file
void solve();

auto main() -> int {
    speedup();
    solve();
    return 0;
}

// Include the problem-specific implementation

#include <iostream>
#include <unordered_map>

enum class Player {
  ANNA,
  KATIE,
};

const std::unordered_map<Player, std::string> name = {
    {Player::ANNA, "First"},
    {Player::KATIE, "Second"},
};

auto play(int a, int b) -> Player {
  if (a > b) {
    return Player::ANNA;
  } else {
    return Player::KATIE;
  }
}

auto play() -> Player {
  int a, b, c;
  std::cin >> a >> b >> c;

  return play(a, b - (c % 2));
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    auto winner = play();
    std::cout << name.at(winner) << "\n";
  }
}
