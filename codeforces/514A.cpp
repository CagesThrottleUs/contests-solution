#include <cstddef>
#include <cstdint>
#include <iostream>

void solve() noexcept {
  const std::int32_t MAX_DIGIT = 9;

  std::size_t curr_idx{0};

  char num_ch{};
  while (std::cin >> num_ch) {
    std::int32_t num = (num_ch - '0');

    std::int32_t complement = MAX_DIGIT - num;

    const char complement_ch = static_cast<char>(complement + '0');

    if ((curr_idx == 0 and num == MAX_DIGIT) or (complement > num)) {
      [[unlikely]] std::cout << num_ch;
    } else {
      std::cout << complement_ch;
    }
    curr_idx++;
  }
  std::cout << '\n';
}