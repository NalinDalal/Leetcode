/* 100. Same Tree
Given the roots of two binary trees p and q, write a function to check if they
are the same or not. Two binary trees are considered the same if they are
structurally identical, and the nodes have the same value.



Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false


Constraints:

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104
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

// what to do:
// 1. if both are null, return ture
// 2. if one is null, other is not, return false
// 3. if both are not null, check if they have the same value
// 4. if same value, check for left and right
// 5. if left and right are not null, check if they are same or not
// 6. if same return true, else return false
// 7. repeat step 5,6 in recusrion until leaf node or one of them is null
class Solution {
public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if ((p == nullptr) & (q == nullptr))
      return true;
    if (p == nullptr | q == nullptr)
      return false;
    if (p->val != q->val)
      return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};

// Time: O(n)
// Space: O(log n)
