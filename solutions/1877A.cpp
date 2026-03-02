#include <iostream>

#ifdef __GNUC__
#ifndef __clang__
#pragma GCC optimize("O3", "unroll-loops")
#endif
#endif

void speedup() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

// Forward declaration - to be implemented in problem file
void solve();

auto main() -> int {
    speedup();
    solve();
    return 0;
}

// Include the problem-specific implementation

#include <iostream>

auto work() -> int
{
    int num_elements{};
    std::cin >> num_elements;

    int sum{0};
    for (int i{0}; i < num_elements - 1; i++)
    {
        int input{};
        std::cin >> input;
        sum += input;
    }
    return -1*sum;
}

void solve()
{
    int num_test_cases{};
    std::cin >> num_test_cases;

    while (num_test_cases > 0)
    {
        num_test_cases--;
        std::cout << work() << "\n";
    }
}
