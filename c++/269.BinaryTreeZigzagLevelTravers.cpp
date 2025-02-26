/* 103. Binary Tree Zigzag Level Order Traversal

Given the root of a binary tree, return the zigzag level order traversal of its
nodes' values. (i.e., from left to right, then right to left for the next level
and alternate between).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []


Constraints:
The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for a binary tree node.

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    // return zigzag level order traversal of the tree
    vector<vector<int>> ans;
    if (root == NULL)
      return ans;

    queue<TreeNode*> q; // maintain a queue for easy push and pop
    q.push(root);
    bool leftToRight = true; // Flag to track the direction of traversal

    while (!q.empty()) {
      int sz = q.size();
      vector<int> level(sz); // initialsed vector so that we can push
      // pop element easily

      for (int i = 0; i < sz; i++) {
        TreeNode* temp = q.front();
        q.pop();

        // Determine index based on direction (left to right or right to left)
        int index = (leftToRight) ? i : (sz - 1 - i);

        level[index] = temp->val; // push the node itself

        if (temp->left)
          q.push(temp->left); // push left child of node
        if (temp->right)
          q.push(temp->right); // push right child of node
      }

      ans.push_back(level);
      leftToRight = !leftToRight; // Toggle the direction for the next level
    }

    return ans; // return ans array
  }
};

// 100%
// sub:
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/1556121494/
// sol:
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/solutions/6470785/103-binary-tree-zigzag-level-order-trave-sihb/
