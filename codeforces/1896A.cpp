#include <iostream>

void work()
{
    int num_elements{};
    std::cin >> num_elements;

    bool is_first_num_1{false};
    for (int i{0}; i < num_elements; i++)
    {
        int input{};
        std::cin >> input;
        if (i == 0)
        {
            is_first_num_1 = input == 1;
        }
    }

    std::cout << (is_first_num_1 ? "YES" : "NO") << "\n";
}

void solve()
{
    int num_test_cases{};
    std::cin >> num_test_cases;

    while (num_test_cases > 0)
    {
        num_test_cases--;
        work();
    }
}