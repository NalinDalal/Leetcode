/* 101. Symmetric Tree
Easy
Topics
Companies
Given the root of a binary tree, check whether it is a mirror of itself (i.e.,
symmetric around its center).



Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false


Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100


Follow up: Could you solve it both recursively and iteratively?
*/

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

// to find if symmetric around root node
// if root==NULL return true
// wrong ans
/* class Solution {
public:
  bool isSymmetric(TreeNode* root) {
    if (root == NULL)
      return true;
    else if (root->left == NULL && root->right == NULL)
      return true;
    else if (root->left == NULL || root->right == NULL)
      return false;
    return isSymmetric(root->left);
    return isSymmetric(root->right);
  }
};*/

// wait wait wait
// we need to check if left subtree and right subtree are mirror imagesof each
// other, like left ka left must be right ka right and like that, right ka left
// must be left ka right like that

// approach
/* 1. if root is null, return true
2. if root is not null, check if left and right are mirror images of each other
3. if left and right are mirror images of each other, return true
4. if left and right are not mirror images of each other, return false

logic for mirror-> left must be right, right must be left
left->left==right->right, left->right==right->left
*/

class Solution {
public:
  bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL && t2 == NULL)
      return true; // Both nodes are null, symmetric
    if (t1 == NULL || t2 == NULL)
      return false;             // Only one of the nodes is null, not symmetric
    return (t1->val == t2->val) // Check values
           && isMirror(t1->left, t2->right)  // Left of t1 vs Right of t2
           && isMirror(t1->right, t2->left); // Right of t1 vs Left of t2
  }

  bool isSymmetric(TreeNode* root) {
    if (root == NULL)
      return true; // A null tree is symmetric
    return isMirror(root->left, root->right);
  }
};
// 100% correct
//  Time: O(n)
//  Space: O(1)
