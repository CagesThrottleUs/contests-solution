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
#include <vector>
#include <string>

constexpr int BASE{10};

inline auto get_count_for_not_less_than(const std::vector<int>& eles, int target) -> int {
    auto idx = std::upper_bound(eles.begin(), eles.end(), target);
    return static_cast<int>(std::distance(idx, eles.end()));
}

void solve() {
    int total_elems{};
    if (!(std::cin >> total_elems)) return;

    std::vector<int> eles(total_elems);
    for (int i{0}; i < total_elems; i++) {
        std::cin >> eles[i];
    }

    std::sort(eles.begin(), eles.end());

    int max_ele = eles.back();
    std::string construct{};
    construct.reserve(max_ele + BASE); 

    long long carry{0}; 

    for (int idx{0}; idx < max_ele; idx++) {
        int count_at_pos = get_count_for_not_less_than(eles, idx);
        long long current_sum = carry + count_at_pos;

        construct += std::to_string(current_sum % BASE);
        carry = current_sum / BASE;
    }

    while (carry > 0) {
        construct += std::to_string(carry % BASE);
        carry /= BASE;
    }

    std::reverse(construct.begin(), construct.end());
    std::cout << construct << "\n";
}
