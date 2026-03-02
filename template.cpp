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
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    speedup();
    solve();
    return 0;
}

// Include the problem-specific implementation
#ifdef PROBLEM_FILE
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#include TOSTRING(PROBLEM_FILE)
#endif
