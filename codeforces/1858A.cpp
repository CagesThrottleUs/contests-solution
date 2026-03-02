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