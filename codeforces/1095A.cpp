#include <cstddef>
#include <iostream>
#include <queue>

void solve() noexcept {
  std::size_t size{};
  std::cin >> size;

  std::queue<char> to_process;

  for (std::size_t i{0}; i < size; i++) {
    char _ch{};
    std::cin >> _ch;
    to_process.push(_ch);
  }

  std::size_t pop_out_size{1};

  while (!to_process.empty()) {
    auto item = to_process.front();
    for (std::size_t i{0}; i < pop_out_size and !to_process.empty(); i++) {
      to_process.pop();
    }
    std::cout << item;
    pop_out_size++;
  }

  std::cout << "\n";
}