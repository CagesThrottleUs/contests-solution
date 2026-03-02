#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

constexpr int BASE{10};

inline auto get_count_for_not_less_than(const std::vector<int> &eles, int target) -> int
{
    auto idx = std::upper_bound(eles.begin(), eles.end(), target);
    return static_cast<int>(std::distance(idx, eles.end()));
}

void solve()
{
    int total_elems{};
    if (!(std::cin >> total_elems))
    {
        return;
    }
    
    std::vector<int> eles(total_elems);
    for (int i{0}; i < total_elems; i++)
    {
        std::cin >> eles[i];
    }

    std::sort(eles.begin(), eles.end());

    int max_ele = eles.back();
    std::string construct{};
    construct.reserve(max_ele + BASE);

    long long carry{0};

    for (int idx{0}; idx < max_ele; idx++)
    {
        int count_at_pos = get_count_for_not_less_than(eles, idx);
        long long current_sum = carry + count_at_pos;

        construct += std::to_string(current_sum % BASE);
        carry = current_sum / BASE;
    }

    while (carry > 0)
    {
        construct += std::to_string(carry % BASE);
        carry /= BASE;
    }

    std::reverse(construct.begin(), construct.end());
    std::cout << construct << "\n";
}