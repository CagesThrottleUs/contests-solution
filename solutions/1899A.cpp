#include <iostream>

void speedup() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
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

void solve()
{
    int num_test_cases{};
    std::cin >> num_test_cases;

    while (num_test_cases > 0)
    {
        num_test_cases--;
        int input{};
        std::cin >> input;
        std::cout << (input % 3 == 0 ? "Second" : "First") << "\n";
    }
}
