/*
 *   MIT License
 *
 *   Copyright (c) 2026 CagesThrottleUs
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <array>
#include <cstddef>
#include <cstdint>
#include <string>
#include <utility>

// Combinatorial counting via prefix enumeration.
//
// For N in [0, 10^16): count 16-digit strings S (with leading zeros) such that
// path digits S[p_0], S[p_1], ..., S[p_6] are non-decreasing.
//
// Split by longest common prefix with N: for each position k, fix S[0..k-1] =
// N[0..k-1], let S[k] = d < N[k], and count free completions for S[k+1..15].
// Plus 1 for S = N if N itself satisfies the constraint.
//
// Free completions for a suffix with P remaining path slots (all >= last_min)
// and F remaining free slots:
//   non-decreasing sequences of length P over [last_min, 9] = C(P + R, R)
//     where R = 9 - last_min (stars and bars)
//   free slots contribute 10^F
class Solution {
  static constexpr std::size_t GRID_SIDE = 4;
  static constexpr std::size_t NUM_DIGITS = 16;
  static constexpr std::size_t PATH_LEN = 7;
  static constexpr int BASE = 10;
  static constexpr std::size_t BINOM_SIZE = PATH_LEN + BASE;          // 17
  static constexpr std::size_t POW_SIZE = NUM_DIGITS - PATH_LEN + 1;  // 10

  using PathMask = std::array<bool, NUM_DIGITS>;
  using PathSuffix = std::array<std::size_t, NUM_DIGITS + 1>;
  using DigitSeq = std::array<int, NUM_DIGITS>;
  using BinomTable =
      std::array<std::array<std::int64_t, BINOM_SIZE>, BINOM_SIZE>;
  using PowTable = std::array<std::int64_t, POW_SIZE>;

  // NOLINTBEGIN(cppcoreguidelines-pro-bounds-constant-array-index)
  static auto make_binom() noexcept -> BinomTable {
    BinomTable binom{};
    for (std::size_t i = 0; i < BINOM_SIZE; ++i) {
      binom[i][0] = 1;
      for (std::size_t j = 1; j <= i; ++j) {
        const std::int64_t right = (j < i) ? binom[i - 1][j] : 0;
        binom[i][j] = binom[i - 1][j - 1] + right;
      }
    }
    return binom;
  }

  static auto make_pow10() noexcept -> PowTable {
    PowTable pow{};
    pow[0] = 1;
    for (std::size_t i = 1; i < POW_SIZE; ++i) {
      pow[i] = pow[i - 1] * BASE;
    }
    return pow;
  }
  // NOLINTEND(cppcoreguidelines-pro-bounds-constant-array-index)

  static inline const BinomTable BINOM = make_binom();
  static inline const PowTable POW10 = make_pow10();

  static auto compute_path_info(const std::string& directions)
      -> std::pair<PathMask, PathSuffix> {
    PathMask on_path{};
    std::size_t row = 0;
    std::size_t col = 0;
    on_path.at(0) = true;
    for (char dir : directions) {
      if (dir == 'D') {
        ++row;
      } else {
        ++col;
      }
      on_path.at((row * GRID_SIDE) + col) = true;
    }
    PathSuffix suffix{};
    for (std::size_t i = NUM_DIGITS; i-- > 0;) {
      suffix.at(i) = suffix.at(i + 1) + (on_path.at(i) ? 1UZ : 0UZ);
    }
    return {on_path, suffix};
  }

  static auto to_digits(std::int64_t num) -> DigitSeq {
    DigitSeq digits{};
    for (std::size_t i = NUM_DIGITS; i-- > 0;) {
      digits.at(i) = static_cast<int>(num % BASE);
      num /= BASE;
    }
    return digits;
  }

  struct SuffixCounts {
    std::size_t path_rem;
    std::size_t free_rem;
  };

  // Valid completions: path_rem path slots non-decreasing with values >=
  // last_min, free_rem free slots in [0, 9].
  static auto completions(SuffixCounts counts, int last_min) -> std::int64_t {
    const auto range = static_cast<std::size_t>((BASE - 1) - last_min);
    return BINOM.at(counts.path_rem + range).at(range) *
           POW10.at(counts.free_rem);
  }

  static auto count_up_to(std::int64_t num, const PathMask& on_path,
                          const PathSuffix& path_suffix) -> std::int64_t {
    if (num < 0) {
      return 0;
    }
    const auto digits = to_digits(num);
    std::int64_t count = 0;
    int last = 0;  // last path digit along the "= N prefix" so far
    for (std::size_t k = 0; k < NUM_DIGITS; ++k) {
      const int upper = digits.at(k);
      const SuffixCounts counts{
          .path_rem = path_suffix.at(k + 1),
          .free_rem = (NUM_DIGITS - 1 - k) - path_suffix.at(k + 1),
      };

      for (int digit = 0; digit < upper; ++digit) {
        int new_last = last;
        if (on_path.at(k)) {
          if (digit < last) {
            continue;
          }
          new_last = digit;
        }
        count += completions(counts, new_last);
      }

      if (on_path.at(k)) {
        if (upper < last) {
          return count;  // N itself violates path constraint at position k
        }
        last = upper;
      }
    }
    return count + 1;  // N itself satisfies the constraint
  }

 public:
  // NOLINTBEGIN(bugprone-easily-swappable-parameters,readability-identifier-length,google-runtime-int,performance-unnecessary-value-param)
  static auto countGoodIntegersOnPath(std::int64_t l, std::int64_t r,
                                      std::string directions) -> std::int64_t {
    const auto [on_path, path_suffix] = compute_path_info(directions);
    const auto upper = count_up_to(r, on_path, path_suffix);
    const auto lower = count_up_to(l - 1, on_path, path_suffix);
    return static_cast<long long>(upper - lower);
  }
  // NOLINTEND(bugprone-easily-swappable-parameters,readability-identifier-length,google-runtime-int,performance-unnecessary-value-param)
};
