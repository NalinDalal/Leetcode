/* 124. Binary Tree Maximum Path Sum

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes
in the sequence has an edge connecting them. A node can only appear in the
sequence at most once. Note that the path does not need to pass through the
root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty
path.



Example 1:
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7
= 42.


Constraints:
The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000 */

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
  int maxPathSum(TreeNode* root) {
    if (!root)
      return 0;
    int left = maxPathSum(root->left);
    int right = maxPathSum(root->right);
    return max(left + root->val, right + root->val);
  }
};
/* The current implementation has several critical flaws:

It doesn't handle the case of a path that goes through the root node
It doesn't track the overall maximum path sum across the entire tree
It incorrectly returns a single path sum instead of the maximum possible path
sum It doesn't account for paths that might include both left and right
subtrees*/

class Solution1 {
private:
  int maxSum = INT_MIN;

  int maxPathSumUtil(TreeNode* node) {
    if (!node)
      return 0;

    // Recursively compute max path sum for left and right subtrees
    int leftSum = max(0, maxPathSumUtil(node->left));
    int rightSum = max(0, maxPathSumUtil(node->right));

    // Update the maximum path sum that goes through the current node
    maxSum = max(maxSum, node->val + leftSum + rightSum);

    // Return the maximum path sum that can be extended to the parent
    return node->val + max(leftSum, rightSum);
  }

public:
  int maxPathSum(TreeNode* root) {
    maxPathSumUtil(root);
    return maxSum;
  }
};

/* For each node, compute the maximum path sum through that node
Consider paths that might go through left subtree, right subtree, or both
Ignore paths with negative sums by using max(0, subtreeSum)
Track the global maximum path sum across the entire tree*/

// time complexity: O(n)
// space complexity:    O(log n)
// 100% correct
