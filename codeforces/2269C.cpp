#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

void solve() noexcept {
  std::uint16_t tests{};
  std::cin >> tests;

  while (tests > 0) {
    tests--;
    std::size_t arr_size{};
    std::size_t op_param{};
    std::cin >> arr_size >> op_param;

    std::vector<std::uint32_t> arr;
    arr.resize(arr_size, 0);
    for (std::size_t i{0}; i < arr_size; i++) {
      std::uint32_t num{};
      std::cin >> num;
      arr.at(i) = num;
    }

    std::uint64_t ans{0};

    if (2 * op_param <= arr_size + 1) {
      // between sum can be extracted
      std::size_t k_idx = op_param - 1;
      std::size_t n_k_idx = arr_size - op_param;

      for (std::size_t i{k_idx}; i <= n_k_idx; i++) {
        ans += arr.at(i);
      }

      for (std::size_t i{0}; i < op_param - 1; i++) {
        ans += std::max(arr.at(i), arr.at(arr_size - 1 - i));
      }
    } else {
      for (std::size_t i{0}; i < arr_size - op_param + 1; i++) {
        ans += std::max(arr.at(i), arr.at(arr_size - 1 - i));
      }
    }

    std::cout << ans << "\n";
  }
}