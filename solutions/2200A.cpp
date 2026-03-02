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
#include <unordered_set>
#include <vector>

auto play(std::vector<int> dish, int start) -> int {
  int cnt_non_zero = dish.size();

  int curr = start;
  int last = 0;

  while (cnt_non_zero > 0) {
    if (dish[curr] > 0) {
      dish[curr]--;
      cnt_non_zero -= (dish[curr] == 0) ? 1 : 0;
    }
    last = curr;
    curr = (curr + 1) % dish.size();
  }

  return last;
}

auto work() -> int {
  int n_people{};
  std::cin >> n_people;

  std::vector<int> dish_cnt(n_people);
  for (int i = 0; i < n_people; i++) {
    std::cin >> dish_cnt[i];
  }

  // start from first person
  std::unordered_set<int> winners;
  for (int i = 0; i < n_people; i++) {
    winners.insert(play(dish_cnt, i));
  }

  return winners.size();
}

void solve() {
  int num_test_cases{};
  std::cin >> num_test_cases;

  while (num_test_cases > 0) {
    num_test_cases--;
    std::cout << work() << "\n";
  }
}
