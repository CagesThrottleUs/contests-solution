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
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

constexpr std::size_t NUM_ALPHABET = 26;
constexpr std::size_t PRIME = 31;

struct Anagram {
  // NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
  std::array<std::size_t, NUM_ALPHABET> counts{};

  explicit Anagram() { counts.fill(0); }

  auto add(const std::string_view& str) -> void {
    for (const auto& _ch : str) {
      counts.at(static_cast<std::size_t>(_ch - 'a'))++;
    }
  }

  auto operator()() const -> std::size_t {
    std::size_t hash{0};
    for (std::size_t i{0}; i < NUM_ALPHABET; i++) {
      hash = (hash * PRIME) + static_cast<std::size_t>(counts.at(i));
    }
    return hash;
  }

  auto operator==(const Anagram& other) const -> bool {
    return counts == other.counts;
  }
};

template <>
struct std::hash<Anagram> {
  auto operator()(const Anagram& anagram) const noexcept -> std::size_t {
    return anagram();
  }
};

class Solution {
  using StringList = std::vector<std::string>;
  using AnagramList = std::vector<std::vector<std::string>>;

 public:
  auto groupAnagrams(StringList& strs) -> AnagramList {
    std::unordered_map<Anagram, StringList> anagram_map;

    for (const auto& str : strs) {
      Anagram anagram;
      anagram.add(str);
      anagram_map[anagram].push_back(str);
    }

    AnagramList result;
    result.reserve(anagram_map.size());
    for (const auto& [anagram, str_list] : anagram_map) {
      result.push_back(str_list);
    }
    return result;
  }
};