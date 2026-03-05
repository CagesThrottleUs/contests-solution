/*
 *   MIT License
 *
 *   Copyright (c) 2026 CagesThrottleUs
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 */


#include <iostream>

void solve() {
  int T;
  std::cin >> T;
  while (T--) {
    long long N, Q;
    std::cin >> N >> Q;
    // f(e,q) = (2e+1)(Q+1) is max N handleable with error e and q queries
    // Min e s.t. (2e+1)(Q+1) >= N
    // => 2e+1 >= ceil(N/(Q+1))
    // => e = ceil((ceil(N/(Q+1)) - 1) / 2) = ceil(N/(Q+1)) / 2  (integer
    // division)
    long long denom = Q + 1;
    long long c = (N + denom - 1) / denom; // ceil(N / (Q+1))
    long long ans = c / 2;
    std::cout << ans << '\n';
  }
}