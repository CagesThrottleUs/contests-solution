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