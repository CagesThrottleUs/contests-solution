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
#include <unordered_map>

auto work() -> bool
{
    int num_elements{};
    std::cin >> num_elements;

    std::unordered_map<int, int> frequency;
    for (int i{0}; i < num_elements; i++)
    {
        int input{};
        std::cin >> input;
        frequency[input]++;
    }

    auto total_unique{frequency.size()};
    if (total_unique == 1)
    {
        return true;
    }

    if (total_unique == 2)
    {
        auto itr = frequency.begin();
        int freq1 = itr->second;
        itr++;
        int freq2 = itr->second;
        return std::abs(freq1 - freq2) <= 1;
    }

    return false;
}

void solve()
{
    int num_test_cases{};
    std::cin >> num_test_cases;

    while (num_test_cases > 0)
    {
        num_test_cases--;
        if (work())
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }
}