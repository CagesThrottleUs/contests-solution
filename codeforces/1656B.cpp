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

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <unordered_set>

struct CustomHash {
  static constexpr std::uint64_t MIX_ADD = 0x9e3779b97f4a7c15ULL;
  static constexpr std::uint64_t MIX_MUL1 = 0xbf58476d1ce4e5b9ULL;
  static constexpr std::uint64_t MIX_MUL2 = 0x94d049bb133111ebULL;
  static constexpr std::uint32_t SHIFT1 = 30U;
  static constexpr std::uint32_t SHIFT2 = 27U;
  static constexpr std::uint32_t SHIFT3 = 31U;

  static auto mix(std::uint64_t val) -> std::uint64_t {
    val += MIX_ADD;
    val = (val ^ (val >> SHIFT1)) * MIX_MUL1;
    val = (val ^ (val >> SHIFT2)) * MIX_MUL2;
    return val ^ (val >> SHIFT3);
  }
  auto operator()(std::uint64_t val) const -> std::size_t {
    static const std::uint64_t SEED = static_cast<std::uint64_t>(
        std::chrono::steady_clock::now().time_since_epoch().count());
    return static_cast<std::size_t>(mix(val + SEED));
  }
};

void solve() {
  std::int32_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    std::int32_t target{};
    std::cin >> size >> target;

    std::unordered_set<std::int32_t, CustomHash> seen;
    seen.reserve(size);
    bool possible{false};

    for (std::size_t i{0}; i < size; i++) {
      std::int32_t num{};
      std::cin >> num;
      if (possible) {
        continue;
      }
      if (seen.contains(num - target) || seen.contains(num + target)) {
        possible = true;
      }
      seen.insert(num);
    }

    std::cout << (possible ? "YES\n" : "NO\n");
  }
}