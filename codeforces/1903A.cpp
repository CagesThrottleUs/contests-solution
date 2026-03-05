/*
 *   MIT License
 *
 *   Copyright (c) 2026 CagesThrottleUs
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 */

// Problem: 1903A
#include <cstdint>
#include <iostream>

void work();

void solve() {
    int num_test_case{0};
    std::cin >> num_test_case;

    while (num_test_case > 0) {
        num_test_case--;
        work();
    }
}

void work() {
    int num_boxes{0};
    int len_reverse{};
    std::cin >> num_boxes >> len_reverse;

    bool is_sorted{true};

    std::uint32_t curr{};
    std::cin >> curr;

    for (int i{1}; i<num_boxes; i++) {
        auto last = curr;
        std::cin >> curr;
        if (last > curr) {
            is_sorted = false;
        }
    }

    if (is_sorted) {
        std::cout << "YES\n";
        return;
    }

    if (len_reverse == 1) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }
}
