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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <memory>
#include <queue>
#include <vector>

struct ListNode {
  int val;         // NOLINT(misc-non-private-member-variables-in-classes)
  ListNode* next;  // NOLINT(misc-non-private-member-variables-in-classes)
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int value) : val(value), next(nullptr) {}
  explicit ListNode(int value, ListNode* next) : val(value), next(next) {}
};

class Solution {
 public:
  static auto mergeKLists(std::vector<ListNode*>& lists) -> ListNode* {
    using ListNode_t = ListNode*;
    auto cmp = [](const ListNode_t& lhs, const ListNode_t& rhs) -> bool {
      return lhs->val > rhs->val;
    };
    std::priority_queue<ListNode_t, std::vector<ListNode_t>, decltype(cmp)> queue(cmp);

    for (const auto& list : lists) {
      if (list != nullptr) {
        queue.push(list);
      }
    }

    auto dummy = std::make_unique<ListNode>(0);
    ListNode_t current = dummy.get();

    while (!queue.empty()) {
      auto* node = queue.top();
      queue.pop();
      current->next = node;
      current = current->next;
      if (node->next != nullptr) {
        queue.push(node->next);
      }
    }

    auto* res = dummy->next;
    dummy->next = nullptr;

    return res;
  }
};