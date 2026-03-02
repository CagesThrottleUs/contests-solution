#include <iostream>

void solve()
{
    char dig1{};
    char dig2{};
    char dig3{};
    std::cin >> dig1 >> dig2 >> dig3;

    if (dig1 == dig2 && dig2 == dig3)
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }
}