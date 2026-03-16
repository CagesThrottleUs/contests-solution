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

#include <cstdint>
#include <iostream>
#include <numeric>

constexpr std::int64_t ONE_PERSON = 6;
constexpr std::int64_t TWO_PERSON = 3;
constexpr std::int64_t THREE_PERSON = 2;

// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
auto find_total(std::int64_t total_days, std::int64_t rep,
                // NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
                std::int64_t lcm_two_ele_1, std::int64_t lcm_two_ele_2,
                std::int64_t lcm_three) -> std::int64_t {
  auto total_eles = total_days / rep;

  auto two_eles = (total_days / lcm_two_ele_1) + (total_days / lcm_two_ele_2);

  auto three_eles = total_days / lcm_three;

  return (ONE_PERSON * total_eles) - ((TWO_PERSON) * two_eles) +
         (THREE_PERSON * three_eles);
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::int64_t rep_a{};
    std::int64_t rep_b{};
    std::int64_t rep_c{};
    std::int64_t total_days{};
    std::cin >> rep_a >> rep_b >> rep_c >> total_days;

    // std::cout << "Rep A: " << rep_a << "\n";
    // std::cout << "Rep B: " << rep_b << "\n";
    // std::cout << "Rep C: " << rep_c << "\n";
    // std::cout << "Total days: " << total_days << "\n";

    std::int64_t lcm_ab = std::lcm(rep_a, rep_b);
    std::int64_t lcm_bc = std::lcm(rep_b, rep_c);
    std::int64_t lcm_ac = std::lcm(rep_a, rep_c);
    std::int64_t lcm_abc = std::lcm(lcm_ab, rep_c);

    // std::cout << "LCM AB: " << lcm_ab << "\n";
    // std::cout << "LCM BC: " << lcm_bc << "\n";
    // std::cout << "LCM AC: " << lcm_ac << "\n";
    // std::cout << "LCM ABC: " << lcm_abc << "\n";

    std::cout << find_total(total_days, rep_a, lcm_ab, lcm_ac, lcm_abc) << " ";
    std::cout << find_total(total_days, rep_b, lcm_ab, lcm_bc, lcm_abc) << " ";
    std::cout << find_total(total_days, rep_c, lcm_ac, lcm_bc, lcm_abc) << "\n";
  }
}