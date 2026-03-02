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
    char dig1{};
    char dig2{};
    char dig3{};
    std::cin >> dig1 >> dig2 >> dig3;

    if (dig1 == dig2 && dig2 == dig3)
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }
}
