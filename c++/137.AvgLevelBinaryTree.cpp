/* 637. Average of Levels in Binary Tree

Given the root of a binary tree, return the average value of the nodes on each
level in the form of an array. Answers within 10-5 of the actual answer will be
accepted.


Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and
on level 2 is 11. Hence return [3, 14.5, 11].

Example 2:
Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]


Constraints:
The number of nodes in the tree is in the range [1, 10^4].
-2^31 <= Node.val <= 2^31 - 1*/

#include <queue>
#include <vector>
using std::vector, std::queue;

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
// 1. get nodes via bfs search
// 2. get their level, and sum up the values
// 3. divide the sum by the number of nodes on that level
class Solution {
public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;
    if (root == nullptr)
      return res;
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
      int size = q.size();
      double sum = 0;
      for (int i = 0; i < size; i++) {
        TreeNode* cur = q.front();
        q.pop();
        sum += cur->val;
        if (cur->left != nullptr)
          q.push(cur->left);
        if (cur->right != nullptr)
          q.push(cur->right);
      }
      res.push_back(sum / size);
      level++;
    }
    return res;
  }
};

/* - Time complexity: $$O(n^2)$$

- Space complexity: $$O(n)$$*/
