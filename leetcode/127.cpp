#include <cstddef>
#include <cstdint>
#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

class Solution {
  using Visited = std::unordered_set<std::string>;
  static auto generate_combinations(std::string& word, Visited& allowed)
      -> std::vector<std::string> {
    std::vector<std::string> combinations;
    for (std::size_t i{0}; i < word.length(); i++) {
      const auto original = word.at(i);
      for (char _ch = 'a'; _ch <= 'z'; _ch++) {
        if (_ch == original) {
          continue;
        }
        word.at(i) = _ch;
        if (allowed.contains(word)) {
          allowed.erase(word);
          combinations.push_back(word);
        }
      }
      word.at(i) = original;
    }
    return combinations;
  }

 public:
  static auto ladderLength(std::string beginWord, std::string endWord,
                           std::vector<std::string>& wordList) -> std::int32_t {
    std::unordered_set<std::string> allowed(wordList.begin(), wordList.end());

    if (!allowed.contains(endWord)) {
      return 0;
    }

    std::queue<std::pair<std::string, std::int32_t>> processor;
    processor.emplace(beginWord, 1);

    while (!processor.empty()) {
      auto word{processor.front().first};
      auto seq_len{processor.front().second};

      processor.pop();

      if (word == endWord) {
        return seq_len;
      }

      auto combinations = generate_combinations(word, allowed);
      for (const auto& combination : combinations) {
        processor.emplace(combination, seq_len + 1);
      }
    }
    return 0;
  }
};