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

#include <iostream>

auto work() -> int {
    int num_stations{};
    int final_position{};
    std::cin >> num_stations >> final_position;

    int curr_pos{0};
    int min_fuel_required{0};

    for (int i{0}; i<num_stations; i++) {
        int next_pos{};
        std::cin >> next_pos;

        
        min_fuel_required = std::max(min_fuel_required, (next_pos - curr_pos));
        
        curr_pos = next_pos;
    }

    min_fuel_required = std::max(min_fuel_required, 2*(final_position - curr_pos));

    return min_fuel_required;
}

void solve() {
    int num_test_case{};
    std::cin >> num_test_case;

    while (num_test_case > 0) {
        num_test_case--;
        auto sol = work();
        std::cout << sol << "\n";
    }
}
