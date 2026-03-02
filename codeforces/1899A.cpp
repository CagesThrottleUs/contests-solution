#include <iostream>

void solve()
{
    int num_test_cases{};
    std::cin >> num_test_cases;

    while (num_test_cases > 0)
    {
        num_test_cases--;
        int input{};
        std::cin >> input;
        std::cout << (input % 3 == 0 ? "Second" : "First") << "\n";
    }
}