#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iostream>
#include <vector>

auto get_gaps(std::size_t infected_cnt, std::size_t total)
    -> std::vector<std::size_t> {
  std::vector<std::size_t> infected;
  infected.reserve(infected_cnt);

  for (std::size_t i{0}; i < infected_cnt; i++) {
    std::size_t node{};
    std::cin >> node;
    infected.push_back(node);
  }

  std::ranges::sort(infected);

  std::vector<std::size_t> gaps;

  for (std::size_t i{0}; i < infected.size() - 1; i++) {
    gaps.push_back(infected.at(i + 1) - infected.at(i) - 1);
  }
  gaps.push_back(infected.at(0) + total - infected.at(infected_cnt - 1) - 1);

  std::ranges::sort(gaps, std::greater<>());

  return gaps;
}

void solve() {
  std::uint32_t tests{};
  std::cin >> tests;

  while (tests > 0) {
    tests--;
    std::size_t total_cnt{};
    std::size_t infected_cnt{};
    std::cin >> total_cnt >> infected_cnt;

    auto gaps = get_gaps(infected_cnt, total_cnt);

    std::size_t num_saved{0};
    std::size_t num_days{0};

    for (const auto& gap : gaps) {
      auto curr_gap = (2 * num_days > gap) ? 0 : gap - (2 * num_days);
      if (curr_gap == 1) {
        num_saved++;
        num_days += 2;
      } else if (curr_gap > 1) {
        num_saved += curr_gap - 1;
        num_days += 2;
      }
    }

    std::cout << total_cnt - num_saved << "\n";
  }
}