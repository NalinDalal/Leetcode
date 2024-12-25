/*    https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/?envType=daily-question&envId=2024-12-25

515. Find Largest Value in Each Tree Row
Given the root of a binary tree, return an array of the largest value in each
row of the tree (0-indexed).

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]

Example 2:
Input: root = [1,2,3]
Output: [1,3]


Constraints:
The number of nodes in the tree will be in the range [0, 10^4].
-2^31 <= Node.val <= 2^31 - 1*/

#include <algorithm>
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

// do bfs search and append largest value in a vector
// return the vector
class Solution {
public:
  vector<int> largestValues(TreeNode* root) {
    vector<int> ans;
    if (root == NULL)
      return ans; // If the tree is empty, return an empty vector.

    queue<TreeNode*> q; // Queue for BFS.
    q.push(root);

    while (!q.empty()) {
      int levelSize = q.size(); // Number of nodes at the current level.
      int maxVal =
          INT_MIN; // Initialize the maximum value for the current level.

      for (int i = 0; i < levelSize; ++i) {
        TreeNode* node = q.front();
        q.pop();

        maxVal = max(maxVal, node->val); // Update the maximum value.

        // Add child nodes to the queue for the next level.
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }

      ans.push_back(maxVal); // Append the largest value of the current level
                             // to the result.
    }

    return ans;
  }
};

// Time complexity: $$O(n)$$ n-number of nodes
// Space complexity:$$O(w)$$ w-max width of tree
