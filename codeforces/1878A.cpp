#include <iostream>

void work()
{
    int num_elements{};
    int num_to_check{};
    std::cin >> num_elements >> num_to_check;

    bool is_possible{false};
    for (int i{0}; i < num_elements; i++)
    {
        int input{};
        std::cin >> input;
        if (input == num_to_check)
        {
            is_possible = true;
        }
    }
    std::cout << (is_possible ? "YES" : "NO") << "\n";
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