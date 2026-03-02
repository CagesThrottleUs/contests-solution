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

#include <algorithm>
#include <iostream>
#include <string>

auto work() -> int {
    int n{};
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int total{0}, run{0}, max_run{0};
    for (char c : s) {
        if (c == '.') {
            ++total;
            max_run = std::max(max_run, ++run);
        } else {
            run = 0;
        }
    }
    return max_run >= 3 ? 2 : total;
}

void solve()
{
    int test_cases{};
    std::cin >> test_cases;

    while (test_cases > 0)
    {
        test_cases--;
        auto sol = work();
        std::cout << sol << "\n";
    }
}
