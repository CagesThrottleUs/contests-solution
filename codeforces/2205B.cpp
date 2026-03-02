#include <iostream>
#include <set>

auto get_primes(int num) -> std::set<int> {
  std::set<int> factors;

  // Handle 2 separately to allow for incrementing by 2 in the loop
  while (num % 2 == 0) {
    factors.insert(2);
    num /= 2;
  }

  // Check odd numbers from 3 up to sqrt(n)
  for (int i = 3; i * i <= num; i += 2) {
    while (num % i == 0) {
      factors.insert(i);
      num /= i;
    }
  }

  // If n is still > 1, the remaining n must be prime
  if (num > 1) {
    factors.insert(num);
  }

  return factors;
}

auto multiply_primes(const std::set<int> &primes) -> int {
  int result = 1;
  for (int prime : primes) {
    result *= prime;
  }
  return result;
}

void solve() {
  int num_test_cases{};
  std::cin >> num_test_cases;
  while (num_test_cases--) {
    int num;
    std::cin >> num;
    auto primes = get_primes(num);
    auto product = multiply_primes(primes);
    std::cout << product << "\n";
  }
}