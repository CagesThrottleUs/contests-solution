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

#include <algorithm>
#include <array>
#include <cstddef>
#include <iostream>
#include <string>

void solve() {
  std::string str;
  std::cin >> str;

  std::array<std::size_t, 26> counts;
  counts.fill(0);
  for (const auto &ch : str) {
    counts[ch - 'a']++;
  }

  auto max_count = *std::max_element(counts.begin(), counts.end());

  std::string res;
  for (const auto &ch : str) {
    if (counts[ch - 'a'] == max_count) {
      continue;
    } else {
      res.push_back(ch);
    }
  }

  std::cout << res << "\n";
}
