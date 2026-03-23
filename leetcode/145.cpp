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
#include <list>
#include <unordered_map>
#include <utility>

class LRUCache {
 private:
  using cache_type = std::list<std::pair<int, int>>;
  using cache_iterator = cache_type::iterator;

  void put_to_front(cache_iterator itr) {
    cache.splice(cache.begin(), cache, itr);
    // list iterators remain valid after splice — no map update needed
  }

 public:
  explicit LRUCache(int capacity): capacity(static_cast<std::size_t>(capacity)) {
    iterator_map.reserve(static_cast<std::size_t>(capacity));
  }

  auto get(int key) -> int {
    auto map_itr = iterator_map.find(key);
    if (map_itr != iterator_map.end()) {
      put_to_front(map_itr->second);
      return map_itr->second->second;
    }
    return -1;
  }

  void put(int key, int value) {
    auto map_itr = iterator_map.find(key);
    if (map_itr != iterator_map.end()) {
      map_itr->second->second = value;
      put_to_front(map_itr->second);
      return;
    }

    if (iterator_map.size() == capacity) {
      iterator_map.erase(cache.back().first);
      cache.pop_back();
    }
    cache.emplace_front(key, value);
    iterator_map[key] = cache.begin();
  }

 private:
  cache_type cache;
  std::size_t capacity;
  std::unordered_map<int, cache_iterator> iterator_map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */