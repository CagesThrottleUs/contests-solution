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
