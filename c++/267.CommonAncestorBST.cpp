/* 235. Lowest Common Ancestor of a Binary Search Tree

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of
two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is
defined between two nodes p and q as the lowest node in T that has both p and q
as descendants (where we allow a node to be a descendant of itself).”



Example 1:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of
itself according to the LCA definition.

Example 3:
Input: root = [2,1], p = 2, q = 1
Output: 2


Constraints:
The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the BST.
*/
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // return a node T such that p and q are descendants of T
    // now the given vector is like bfs order
    if (root == nullptr)
      return nullptr;
    if (root == p || root == q)
      return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left != nullptr && right != nullptr)
      return root;
    return left != nullptr ? left : right;
  }
};

// sub:
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/1554422584/
// sol:
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solutions/6464492/235-lowest-common-ancestor-of-a-binary-s-il6c/

// improvised
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root)
      return nullptr; // Base case: if root is null, return null

    if (root == p || root == q)
      return root; // If root is either p or q, return root

    TreeNode* left = lowestCommonAncestor(root->left, p,
                                          q); // Recursively search left subtree
    TreeNode* right = lowestCommonAncestor(
        root->right, p, q); // Recursively search right subtree

    if (left && right)
      return root; // If both left and right subtrees return non-null, root is
                   // LCA

    return left ? left : right; // Otherwise, return the non-null subtree
                                // (either left or right)
  }
};
