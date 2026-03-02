#include <iostream>

constexpr int BASE{10};

constexpr auto get_sum_of_digits(int num) -> int
{
    int sum{0};
    while (num > 0)
    {
        sum += num % BASE;
        num /= BASE;
    }
    return sum;
}

void solve()
{
    int upper_limit{};
    int sum_of_digits{};
    std::cin >> upper_limit >> sum_of_digits;

    int result{0};
    for (int i{1}; i <= upper_limit; i++)
    {
        if (get_sum_of_digits(i) == sum_of_digits)
        {
            result++;
        }
    }
    std::cout << result << "\n";
}