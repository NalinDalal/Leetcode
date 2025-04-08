/* 530. Minimum Absolute Difference in BST
Given the root of a Binary Search Tree (BST), return the minimum absolute
difference between the values of any two different nodes in the tree.



Example 1:
Input: root = [4,2,6,1,3]
Output: 1

Example 2:
Input: root = [1,0,48,null,null,12,49]
Output: 1


Constraints:
The number of nodes in the tree is in the range [2, 104].
0 <= Node.val <= 105

*/
// Intuition: in-order traversal property of BSTs.
/*Approach
1. Traverse the tree in-order.

2. Track the previous value.

3. Compute the absolute difference between current and previous values.

4. Keep track of the minimum difference.
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int minDiff = INT_MAX;
  TreeNode* prev = nullptr;

  int getMinimumDifference(TreeNode* root) {
    inOrder(root);
    return minDiff;
  }

  void inOrder(TreeNode* node) {
    if (!node)
      return;

    inOrder(node->left);

    if (prev) {
      minDiff = min(minDiff, abs(node->val - prev->val));
    }

    prev = node;

    inOrder(node->right);
  }
};
// Time: O(n)
// Space: O(h)
//  sub:
//  https://leetcode.com/problems/minimum-absolute-difference-in-bst/submissions/1600154011/?envType=study-plan-v2&envId=top-interview-150
//  sol:
//  https://leetcode.com/problems/minimum-absolute-difference-in-bst/solutions/6627381/530-minimum-absolute-difference-in-bst-b-lk6i/
