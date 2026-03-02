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