/*
 *   Copyright (c) 2026 CagesThrottleUs
 *   All rights reserved.
 */
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

/*
 *   Copyright (c) 2026 CagesThrottleUs
 *   All rights reserved.
 */
#include <iostream>

void solve() {
    int a, b;
    std::cin >> a >> b;

    if (a > b) {
        std::cout << "Alice\n";
    } else if (a < b) {
        std::cout << "Bob\n";
    } else {
        std::cout << "Draw\n";
    }
}
