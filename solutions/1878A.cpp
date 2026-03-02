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

void work()
{
    int num_elements{};
    int num_to_check{};
    std::cin >> num_elements >> num_to_check;

    bool is_possible{false};
    for (int i{0}; i < num_elements; i++)
    {
        int input{};
        std::cin >> input;
        if (input == num_to_check)
        {
            is_possible = true;
        }
    }
    std::cout << (is_possible ? "YES" : "NO") << "\n";
}

void solve()
{
    int num_test_cases{};
    std::cin >> num_test_cases;

    while (num_test_cases > 0)
    {
        num_test_cases--;
        work();
    }
}
