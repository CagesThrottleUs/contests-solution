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

#include <algorithm>
#include <iostream>
#include <vector>

void solve()
{
    int total_eles{};
    std::cin >> total_eles;

    std::vector<int> eles(total_eles);
    for (int i{0}; i < total_eles; i++)
    {
        std::cin >> eles[i];
    }

    std::sort(eles.begin(), eles.end());

    int count_max_ele{0};
    for (int i{total_eles - 1}; i >= 0; i--)
    {
        if (eles[i] == eles.back())
        {
            count_max_ele++;
        }
        else
        {
            break;
        }
    }

    if ((total_eles - count_max_ele) % 2 == 0)
    {
        std::cout << eles.back() << "\n";
    }

    if (total_eles % 2 == 0)
    {
        // check if sum of first and last elem == second and second last elem and so on
        for (int i{0}; i < total_eles / 2; i++)
        {
            if (eles[i] + eles[total_eles - i - 1] != eles.front() + eles.back())
            {
                // std::cout << "No\n";
                return;
            }
        }
        std::cout << eles.front() + eles.back() << "\n";
    }
}