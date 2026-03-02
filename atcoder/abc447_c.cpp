#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

struct CurrentResult {
  std::size_t count_a{0};
  char current_char{'\0'};
};

auto get_results(const std::string &str) -> std::vector<CurrentResult> {
  std::vector<CurrentResult> results;
  std::size_t cnt_a{0};
  for (const auto &ch : str) {
    if (ch == 'A') {
      cnt_a++;
    } else {
      results.push_back({cnt_a, ch});
      cnt_a = 0;
    }
  }
  results.push_back({cnt_a, '\0'});
  return results;
}

void solve() {
  std::string s, t;
  std::cin >> s >> t;

  auto s_results = get_results(s);
  auto t_results = get_results(t);

//   std::cout << "s size: " << s_results.size() << "\n";
//   std::cout << "t size: " << t_results.size() << "\n";

  if (s_results.size() != t_results.size()) {
    std::cout << -1 << "\n";
    return;
  }

  std::size_t min_op{0};

  for (std::size_t i{0}; i < s_results.size(); i++) {
    if (s_results[i].current_char != t_results[i].current_char) {
      std::cout << -1 << "\n";
      return;
    } else {
      min_op += (s_results[i].count_a > t_results[i].count_a)
                    ? (s_results[i].count_a - t_results[i].count_a)
                    : (t_results[i].count_a - s_results[i].count_a);
    }
  }
  std::cout << min_op << "\n";
}