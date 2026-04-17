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

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
void solve() {
  std::int32_t tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::string str{};
    std::cin >> str;

    std::unordered_set<char> alphabet;
    for (const auto& _ch : str) {
      alphabet.insert(_ch);
    }

    std::unordered_map<char, std::size_t> last_known_pos;
    bool impossible{false};
    std::size_t left{0};

    for (std::size_t i{0}; i < str.length(); i++) {
      // std::cout << "Processing: " << str[i] << " at index " << i << "\n";
      // std::cout << "Alphabet size: " << alphabet.size() << "\n";
      // std::cout << "Last known pos size: " << last_known_pos.size() << "\n";
      if (!last_known_pos.contains(str[i])) {
        last_known_pos[str[i]] = i;
        // std::cout << "Inserting: " << str[i] << " at index " << i << "\n";
        continue;
      }

      auto prev_pos = last_known_pos[str[i]];
      // std::cout << "Previous position: " << prev_pos << "\n";
      while (left <= prev_pos) {
        // std::cout << "Erasing: " << str[left] << " at index " << left <<
        // "\n";
        last_known_pos.erase(str[left]);
        left++;
      }
      // std::cout << "Inserting: " << str[i] << " at index " << i << "\n";
      last_known_pos[str[i]] = i;

      if (alphabet.size() != last_known_pos.size()) {
        // std::cout << "Alphabet size: " << alphabet.size() << "\n";
        // std::cout << "Last known pos size: " << last_known_pos.size() <<
        // "\n"; std::cout << "Impossible\n";
        impossible = true;
        break;
      }
    }

    std::cout << (impossible ? "NO\n" : "YES\n");
  }
}