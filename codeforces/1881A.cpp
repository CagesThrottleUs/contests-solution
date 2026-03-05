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
#include <string>
#include <vector>

#include <cmath>

auto get_start_pos(const std::string &first_str, const std::string &second_str) -> std::vector<std::size_t>
{
    std::vector<std::size_t> start_pos;
    for (std::size_t i{0}; i < first_str.size(); i++)
    {
        if (first_str[i] == second_str[0])
        {
            start_pos.push_back(i);
        }
    }
    return start_pos;
}

auto find_lambda(int min_reps) -> int
{
    // find smallest int greater than log2(min_reps)
    int lambda{0};
    while (std::pow(2, lambda) <= min_reps)
    {
        lambda++;
    }
    return lambda;
}

auto work() -> int
{
    int len_first_str{};
    int len_second_str{};
    std::cin >> len_first_str >> len_second_str;

    std::string first_str{};
    std::cin >> first_str;

    std::string second_str{};
    std::cin >> second_str;

    auto start_pos = get_start_pos(first_str, second_str);
    for (auto pos : start_pos)
    {
        int min_reps{0};
        std::size_t itr_second{0};
        while (itr_second < second_str.size() && first_str[pos] == second_str[itr_second])
        {
            itr_second++;
            auto completed{itr_second == second_str.size()};
            min_reps += (!completed && (pos + 1) >= first_str.size()) ? 1 : 0;
            pos = (pos + 1) % first_str.size();
        }
        if (itr_second == second_str.size())
        {
            return find_lambda(min_reps);
        }
    }
    return -1;
}

void solve()
{
    int num_test_cases{};
    std::cin >> num_test_cases;

    while (num_test_cases > 0)
    {
        num_test_cases--;
        std::cout << work() << "\n";
    }
}
