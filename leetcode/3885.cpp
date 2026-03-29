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

#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

class EventManager {
  std::unordered_map<int, int> event_priority;
  std::map<int, std::set<int>, std::greater<>> event_queue;

 public:
  explicit EventManager(std::vector<std::vector<int>>& events) {
    for (const auto& event : events) {
      auto event_id = event[0];
      auto priority = event[1];
      event_priority[event_id] = priority;
      event_queue[priority].insert(event_id);
    }
  }

  // NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
  void updatePriority(int eventId, int newPriority) {
    auto old_priority = event_priority[eventId];
    event_queue[old_priority].erase(eventId);
    if (event_queue[old_priority].empty()) {
      event_queue.erase(old_priority);
    }
    event_priority[eventId] = newPriority;
    event_queue[newPriority].insert(eventId);
  }

  auto pollHighest() -> int {
    if (event_queue.empty()) {
      return -1;
    }
    // Get the highest priority event
    auto event_id = event_queue.begin()->second.begin();
    auto val = *event_id;
    event_priority.erase(val);
    event_queue.begin()->second.erase(event_id);
    if (event_queue.begin()->second.empty()) {
      event_queue.erase(event_queue.begin());
    }
    return val;
  }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */