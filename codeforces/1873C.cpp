#include <cstddef>
#include <iostream>

constexpr int GRID_SIZE = 10;

auto get_score(std::size_t i, std::size_t j) -> int {
  if (i >= GRID_SIZE / 2) {
    i = GRID_SIZE - i - 1;
  }
  int max_score = i + 1;

  if (j >= i && j <= GRID_SIZE - i - 1) {
    return max_score;
  } else {
    if (j < i) {
      return max_score + (j - i);
    } else {
      return max_score + (GRID_SIZE - i - 1 - j);
    }
  }
}

auto work() -> int {
  std::size_t i{0};
  std::size_t j{0};

  int score{0};

  for (i = 0; i < GRID_SIZE; i++) {
    for (j = 0; j < GRID_SIZE; j++) {
      char cell{};
      std::cin >> cell;
      if (cell == 'X') {
        auto idx_score = get_score(i, j);
        score += idx_score;
        // std::cout << "i: " << i << ", j: " << j << ", idx_score: " << idx_score
        //           << "\n";
        // std::cout << "score: " << score << "\n";
      }
    }
  }

  return score;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while (tests--) {
    auto score = work();
    std::cout << score << "\n";
  }
}