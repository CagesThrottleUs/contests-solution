#include <iostream>
#include <set>
#include <vector>

void solve()
{
    int N;
    long long D;
    std::cin >> N >> D;

    std::vector<long long> A(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }

    std::set<long long> window;
    long long count = 0;
    int L = 0;

    for (int R = 0; R < N; ++R)
    {
        // While A[R] conflicts with current window, shrink from left
        while (true)
        {
            auto it = window.lower_bound(A[R]);

            bool conflict = false;
            // Check element immediately >= A[R]
            if (it != window.end() && *it - A[R] < D)
                conflict = true;
            // Check element immediately < A[R]
            if (!conflict && it != window.begin() && A[R] - *std::prev(it) < D)
                conflict = true;

            if (conflict)
            {
                window.erase(A[L]);
                L++;
            }
            else
            {
                break;
            }
        }

        window.insert(A[R]);
        // All subarrays ending at R and starting between L and R are valid
        count += (R - L + 1);
    }

    std::cout << count << std::endl;
}