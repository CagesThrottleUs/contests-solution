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