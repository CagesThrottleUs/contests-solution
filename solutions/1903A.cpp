#include <iostream>

void speedup() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

// Forward declaration - to be implemented in problem file
void solve();

auto main() -> int {
    speedup();
    solve();
    return 0;
}

// Include the problem-specific implementation

#include <cstdint>
#include <iostream>

void work();

void solve() {
    int num_test_case{0};
    std::cin >> num_test_case;

    while (num_test_case > 0) {
        num_test_case--;
        work();
    }
}

void work() {
    int num_boxes{0};
    int len_reverse{};
    std::cin >> num_boxes >> len_reverse;

    bool is_sorted{true};

    std::uint32_t curr{};
    std::cin >> curr;

    for (int i{1}; i<num_boxes; i++) {
        auto last = curr;
        std::cin >> curr;
        if (last > curr) {
            is_sorted = false;
        }
    }

    if (is_sorted) {
        std::cout << "YES\n";
        return;
    }

    if (len_reverse == 1) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }
}
