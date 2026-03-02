#include <vector>

class Solution {
public:
  int minimumOR(std::vector<std::vector<int>>& grid) {
    const int m = static_cast<int>(grid.size());
    int ans = 0;

    // 10^5 < 2^17: for each bit from high to low, try to keep it 0
    for (int k = 16; k >= 0; --k) {
      const int mask = ans | ((1 << k) - 1);  // allowed bits: ans and bits < k

      bool can_avoid = true;
      for (int i = 0; i < m; ++i) {
        bool row_ok = false;
        for (int val : grid[i]) {
          if ((val & ~mask) == 0) {  // val has no bit outside mask => bit k can stay 0
            row_ok = true;
            break;
          }
        }
        if (!row_ok) {
          can_avoid = false;
          break;
        }
      }

      if (!can_avoid)
        ans |= (1 << k);
    }

    return ans;
  }
};
