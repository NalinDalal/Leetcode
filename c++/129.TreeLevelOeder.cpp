/* 102. Binary Tree Level Order Traversal
Given the root of a binary tree, return the level order traversal of its nodes'
values. (i.e., from left to right, level by level).


Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []


Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000*/

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

// what to do:
// 1. use a queue to store nodes
// 2. use stack to store level
// 3. levelOrder -> vector of vector for each level of binary tree
// levelOrder[0]->root
// levelOrder[1]->left
// levelOrder[2]->right
// recursion on levelOrder till node->child=null
// if node->child!=null,push node->child to queue
// else, push and break the loop

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> levelOrder;
    if (!root)
      return levelOrder;

    queue<TreeNode*> q; // Queue to store nodes
    q.push(root);

    while (!q.empty()) {
      int levelSize = q.size(); // Number of nodes at the current level
      vector<int> currentLevel;

      for (int i = 0; i < levelSize; i++) {
        TreeNode* node = q.front();
        q.pop();
        currentLevel.push_back(node->val);

        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }

      levelOrder.push_back(currentLevel); // Add the current level to the result
    }

    return levelOrder;
  }
};

// 100%
// Time:O(n)
// Space:O(n)
