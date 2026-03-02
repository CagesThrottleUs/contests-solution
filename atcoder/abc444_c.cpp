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