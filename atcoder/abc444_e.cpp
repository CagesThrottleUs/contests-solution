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
#include <set>
#include <vector>

void solve()
{
    int N;
    long long D;
    std::cin >> N >> D;

    std::vector<long long> A(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }

    std::set<long long> window;
    long long count = 0;
    int L = 0;

    for (int R = 0; R < N; ++R)
    {
        // While A[R] conflicts with current window, shrink from left
        while (true)
        {
            auto it = window.lower_bound(A[R]);

            bool conflict = false;
            // Check element immediately >= A[R]
            if (it != window.end() && *it - A[R] < D)
                conflict = true;
            // Check element immediately < A[R]
            if (!conflict && it != window.begin() && A[R] - *std::prev(it) < D)
                conflict = true;

            if (conflict)
            {
                window.erase(A[L]);
                L++;
            }
            else
            {
                break;
            }
        }

        window.insert(A[R]);
        // All subarrays ending at R and starting between L and R are valid
        count += (R - L + 1);
    }

    std::cout << count << std::endl;
}