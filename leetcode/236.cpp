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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <stack>
#include <unordered_map>
#include <unordered_set>

struct TreeNode {
  int val;  // NOLINT(misc-non-private-member-variables-in-classes)

  // NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
  TreeNode* left{nullptr};

  // NOLINTNEXTLINE(misc-non-private-member-variables-in-classes)
  TreeNode* right{nullptr};
  explicit TreeNode(int value) : val(value) {}
};

class Solution {
 private:
  static auto generate_parent_map(TreeNode* root, TreeNode* lhs, TreeNode* rhs)
      -> std::unordered_map<TreeNode*, TreeNode*> {
    std::unordered_map<TreeNode*, TreeNode*> parent;
    parent[root] = nullptr;

    std::stack<TreeNode*> stk;
    stk.push(root);

    // DFS with early exit — stop once both targets have a parent entry
    while (!parent.contains(lhs) || !parent.contains(rhs)) {
      auto* node = stk.top();
      stk.pop();
      if (node->left != nullptr) {
        parent[node->left] = node;
        stk.push(node->left);
      }
      if (node->right != nullptr) {
        parent[node->right] = node;
        stk.push(node->right);
      }
    }

    return parent;
  }

 public:
  // NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
  static auto lowestCommonAncestor(TreeNode* root, TreeNode* lhs, TreeNode* rhs)
      -> TreeNode* {
    auto parent = generate_parent_map(root, lhs, rhs);
    // Collect all ancestors of lhs (lhs itself included)
    std::unordered_set<TreeNode*> ancestors;
    for (auto* cur = lhs; cur != nullptr; cur = parent[cur]) {
      ancestors.insert(cur);
    }

    // Walk rhs upward until we hit a shared ancestor
    while (!ancestors.contains(rhs)) {
      rhs = parent[rhs];
    }
    return rhs;
  }
};
