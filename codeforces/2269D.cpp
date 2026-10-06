#include <bit>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

inline auto is_good(std::uint16_t num) -> std::uint16_t {
  return (std::popcount(num) & 1) xor 1;
}

inline void test() noexcept {
  std::size_t arr_size{};
  std::cin >> arr_size;

  std::size_t total_updates{};
  std::cin >> total_updates;

  std::vector<std::uint16_t> arr{};
  arr.resize(arr_size, 0);

  std::size_t good_cnt{0};

  for (std::size_t i{0}; i < arr_size; i++) {
    std::uint16_t num{};
    std::cin >> num;
    arr.at(i) = num;
    good_cnt += is_good(num);
  }

  std::cout << good_cnt;

  while (total_updates > 0) {
    total_updates--;

    std::size_t pos{};
    std::cin >> pos;
    std::uint16_t updated{};
    std::cin >> updated;

    good_cnt -= is_good(arr.at(pos - 1));
    arr.at(pos - 1) = updated;
    good_cnt += is_good(arr.at(pos - 1));

    std::cout << " " << good_cnt;
  }

  std::cout << "\n";
}

void solve() noexcept {
  std::uint16_t tests{};
  std::cin >> tests;

  while (tests > 0) {
    tests--;
    test();
  }
}