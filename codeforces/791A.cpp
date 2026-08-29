#include <cmath>
#include <cstdint>
#include <iostream>

void solve() noexcept {
  constexpr double LOG_10_OF_1_DOT_5 = 0.17609125905;

  double lighter{};
  double heavier{};
  std::cin >> lighter >> heavier;

  auto ans = static_cast<std::int32_t>((log10(heavier) - log10(lighter)) /
                                       LOG_10_OF_1_DOT_5);
  ans++;

  std::cout << ans << "\n";
}