#include <iostream>

auto work() -> int
{
    int num_elements{};
    std::cin >> num_elements;

    int sum{0};
    for (int i{0}; i < num_elements - 1; i++)
    {
        int input{};
        std::cin >> input;
        sum += input;
    }
    return -1*sum;
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