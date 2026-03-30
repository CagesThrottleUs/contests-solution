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

#include <stack>
#include <string>

class Solution {
  static auto create_stack(const std::string& str) -> std::stack<std::string> {
    std::stack<std::string> words;
    std::string word;
    word.reserve(str.length());

    for (const auto& _ch : str) {
      if (_ch == ' ') {
        if (!word.empty()) {
          words.push(word);
          word.clear();
        }
        continue;
      }
      word.append(1, _ch);
    }

    if (!word.empty()) {
      words.push(word);
    }

    return words;
  }

 public:
  static auto reverseWords(std::string str) -> std::string {
    auto words = create_stack(str);
    std::string res;
    res.reserve(str.length());

    res.append(words.top());
    words.pop();

    while (!words.empty()) {
      res.append(1, ' ');
      res.append(words.top());
      words.pop();
    }

    return res;
  }
};