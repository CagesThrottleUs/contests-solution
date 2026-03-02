#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  static constexpr long long INF = 1LL << 60;

  // Parity: 0 = even, 1 = odd. Works for negative numbers.
  static int parity(long long x) { return (x & 1) ? 1 : 0; }

  // Minimum range when we must change exactly the indices in `change_idx`
  // and leave the rest unchanged. For each i in change_idx we choose +1 or -1.
  long long minRange(const vector<int>& nums,
                    const vector<int>& change_idx,
                    const vector<int>& keep_idx) {
    long long min_keep = INF, max_keep = -INF;
    for (int i : keep_idx) {
      long long v = nums[i];
      min_keep = min(min_keep, v);
      max_keep = max(max_keep, v);
    }

    if (change_idx.empty()) {
      return max_keep - min_keep;
    }

    // Sort change indices by nums value. Try cutoffs: first k get +1, rest get -1.
    vector<int> s = change_idx;
    sort(s.begin(), s.end(), [&nums](int a, int b) { return nums[a] < nums[b]; });
    const int m = static_cast<int>(s.size());

    long long best = INF;
    for (int k = 0; k <= m; ++k) {
      long long lo = min_keep, hi = max_keep;
      if (k > 0) {
        lo = min(lo, static_cast<long long>(nums[s[0]]) + 1);
        hi = max(hi, static_cast<long long>(nums[s[k - 1]]) + 1);
      }
      if (k < m) {
        lo = min(lo, static_cast<long long>(nums[s[k]]) - 1);
        hi = max(hi, static_cast<long long>(nums[s[m - 1]]) - 1);
      }
      best = min(best, hi - lo);
    }
    return best;
  }

  // Build change/keep index sets for the given parity pattern.
  // target_parity[i] = desired parity at index i (0 or 1).
  void partitionByPattern(const vector<int>& nums,
                          const vector<int>& target_parity,
                          vector<int>& change_idx,
                          vector<int>& keep_idx) {
    change_idx.clear();
    keep_idx.clear();
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
      if (parity(nums[i]) != target_parity[i])
        change_idx.push_back(i);
      else
        keep_idx.push_back(i);
    }
  }

 public:
  std::vector<int> makeParityAlternating(std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    if (n == 1) {
      return {0, 0};
    }

    vector<int> pattern_a(n), pattern_b(n);
    for (int i = 0; i < n; ++i) {
      pattern_a[i] = i & 1;       // 0 even, 1 odd, 0 even, ...
      pattern_b[i] = 1 - (i & 1); // 1 odd, 0 even, 1 odd, ...
    }

    vector<int> change_a, keep_a, change_b, keep_b;
    partitionByPattern(nums, pattern_a, change_a, keep_a);
    partitionByPattern(nums, pattern_b, change_b, keep_b);

    const int ops_a = static_cast<int>(change_a.size());
    const int ops_b = static_cast<int>(change_b.size());
    const int min_ops = min(ops_a, ops_b);

    long long min_range = INF;
    if (ops_a == min_ops) {
      min_range = min(min_range, minRange(nums, change_a, keep_a));
    }
    if (ops_b == min_ops) {
      min_range = min(min_range, minRange(nums, change_b, keep_b));
    }

    return {min_ops, static_cast<int>(min_range)};
  }
};
