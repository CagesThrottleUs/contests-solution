#include <concepts>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <type_traits>

template <typename F>
  requires std::invocable<F&, bool>
constexpr void process_luck(
    std::size_t number,
    F&& lambda)  // NOLINT(cppcoreguidelines-missing-std-forward)
    noexcept(std::is_nothrow_invocable_v<F&, bool>) {
  constexpr std::size_t BASE = 10;
  constexpr std::size_t SEVEN = 7;
  constexpr std::size_t FOUR = 4;

  if (number == 0) {
    lambda(false);
    return;
  }

  while (number > 0) {
    const auto rem = number % BASE;
    number /= BASE;

    if (rem == FOUR || rem == SEVEN) {
      lambda(true);
    } else {
      lambda(false);
    }
  }
}

void solve() noexcept {
  std::uint64_t number{};
  std::cin >> number;

  std::size_t count_lucky{0};
  auto count_functor = [&count_lucky](bool condition_met) -> void {
    if (condition_met) {
      count_lucky++;
    }
  };

  process_luck(number, count_functor);

  bool is_lucky{true};
  auto lucky_functor = [&is_lucky](bool condition_met) -> void {
    is_lucky = is_lucky and condition_met;
  };

  process_luck(count_lucky, lucky_functor);

  if (is_lucky) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
}