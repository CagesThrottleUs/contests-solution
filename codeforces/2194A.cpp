#include <iostream>

auto work() -> int {
    int num_boards{};
    int width_mower{};
    std::cin >> num_boards >> width_mower;
    
    int divisor = num_boards / width_mower;

    return (divisor*(width_mower - 1)) + (num_boards % width_mower);
}

void solve() {
    int num_test_case{};
    std::cin >> num_test_case;

    while (num_test_case > 0) {
        num_test_case--;
        std::cout << work() << "\n";
    }
}