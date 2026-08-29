#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

void solve_test() noexcept {
  std::size_t size{};
  std::size_t max_range{};
  std::cin >> size >> max_range;

  std::vector<std::size_t> freq(max_range + 1, 0);

  for (std::size_t i{0}; i < size; i++) {
    std::size_t num{};
    std::cin >> num;

    freq[num]++;
  }

  std::vector<std::size_t> suffix(max_range + 1, 0);
  suffix.back() = freq.back();

  for (std::size_t i{suffix.size() - 2}; i < suffix.size(); i--) {
    suffix[i] = suffix[i + 1] + freq[i];
  }

  std::size_t ans{0};

  for (std::size_t target{1}; target <= max_range; target++) {
    const auto twice_target = 2 * target;
    const auto freq_val =
        (twice_target >= freq.size()) ? 0 : freq[twice_target];
    ans = std::max(ans, suffix[target] + freq_val);
  }

  std::cout << ans << "\n";
}

void solve() noexcept {
  std::size_t tests{};
  std::cin >> tests;

  while (tests > 0) {
    tests--;
    solve_test();
  }
}