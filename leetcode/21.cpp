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

struct ListNode {
  int val;         // NOLINT(misc-non-private-member-variables-in-classes)
  ListNode* next;  // NOLINT(misc-non-private-member-variables-in-classes)
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int value) : val(value), next(nullptr) {}
  explicit ListNode(int value, ListNode* next) : val(value), next(next) {}
};

class Solution {
 public:
  static auto mergeTwoLists(ListNode* list1, ListNode* list2) -> ListNode* {
    auto head = std::make_unique<ListNode>(0);
    auto* curr = head.get();

    while (list1 != nullptr and list2 != nullptr) {
      if (list1->val < list2->val) {
        curr->next = list1;
        list1 = list1->next;
      } else {
        curr->next = list2;
        list2 = list2->next;
      }
      curr = curr->next;
      curr->next = nullptr;
    }

    if (list1 != nullptr) {
      curr->next = list1;
    } else {
      curr->next = list2;
    }

    curr = (head)->next;
    head->next = nullptr;

    return curr;
  }
};