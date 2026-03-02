constexpr int MOD = 1'000'000'007;

class Solution {
private:
  long long linear_sum(long long r) { return (r * (r + 1)) / 2; }

  long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
      if (b & 1)
        res = res * a % MOD;
      a = a * a % MOD;
      b >>= 1;
    }
    return res;
  }

  // Geometric series 1 + 10 + 10^2 + ... + 10^(k-1) = (10^k - 1) / 9 (mod MOD)
  long long geom10(long long k) {
    long long ten_k = binpow(10, k);
    long long inv9 = binpow(9, MOD - 2);
    return (ten_k - 1 + MOD) % MOD * inv9 % MOD;
  }

  int do_zero(long long r, long long k) {
    long long sum_digits = linear_sum(r);
    long long first_comb = binpow(r + 1, k - 1);
    long long g = geom10(k);
    return static_cast<int>(sum_digits * first_comb % MOD * g % MOD);
  }

public:
  int sumOfNumbers(int l, int r, int k) {
    return sumOfNumbers(static_cast<long long>(l), static_cast<long long>(r),
                        static_cast<long long>(k));
  }

  int sumOfNumbers(long long l, long long r, long long k) {
    if (l == 0) {
      return do_zero(r, k);
    }

    long long sum_digits = linear_sum(r) - linear_sum(l - 1);
    long long digit_combination = binpow(r - l + 1, k - 1);
    long long g = geom10(k);
    return static_cast<int>(sum_digits % MOD * digit_combination % MOD * g % MOD);
  }
};
