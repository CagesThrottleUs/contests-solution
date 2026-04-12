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

#include <iterator>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

constexpr std::size_t MAX_SIZE = 2ULL * 100'000;

class TimeMap {
  std::unordered_map<std::string, std::vector<std::pair<int, std::string>>>
      dict;

 public:
  TimeMap() {
    dict.clear();
    dict.reserve(MAX_SIZE);
  }

  // NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
  void set(const std::string& key, const std::string& value, int timestamp) {
    dict[key].emplace_back(timestamp, value);
  }

  auto get(const std::string& key, int timestamp) -> std::string {
    if (dict.contains(key)) {
      auto first = dict[key].begin();
      auto last = dict[key].end();

      auto count = std::distance(first, last);

      while (count > 0) {
        auto step = count / 2;
        auto itr = first;
        std::advance(itr, step);

        if (itr->first <= timestamp) {
          first = ++itr;
          count -= step + 1;
        } else {
          count = step;
        }
      }

      if (first == dict[key].begin()) {
        return "";
      }
      return std::prev(first)->second;
    }
    return "";
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */