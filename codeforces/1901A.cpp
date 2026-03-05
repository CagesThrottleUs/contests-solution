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

// Problem: 1901A
#include <iostream>

auto work() -> int {
    int num_stations{};
    int final_position{};
    std::cin >> num_stations >> final_position;

    int curr_pos{0};
    int min_fuel_required{0};

    for (int i{0}; i<num_stations; i++) {
        int next_pos{};
        std::cin >> next_pos;

        
        min_fuel_required = std::max(min_fuel_required, (next_pos - curr_pos));
        
        curr_pos = next_pos;
    }

    min_fuel_required = std::max(min_fuel_required, 2*(final_position - curr_pos));

    return min_fuel_required;
}

void solve() {
    int num_test_case{};
    std::cin >> num_test_case;

    while (num_test_case > 0) {
        num_test_case--;
        auto sol = work();
        std::cout << sol << "\n";
    }
}