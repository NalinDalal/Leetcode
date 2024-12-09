/* 110. Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.
A height-balanced binary tree is a binary tree in which the depth of the two
subtrees of every node never differs by more than one.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:
Input: root = []
Output: true


Constraints:

The number of nodes in the tree is in the range [0, 5000].
-10^4 <= Node.val <= 10^4
*/

#include <algorithm>
#include <cmath>
#include <iostream>
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

// Solution:
/* Base Case: if empty tree, return true
 * if not empty tree, check if left and right subtrees are balanced
 * check them recursively balanced factor of 0 or 1 only
 * if not balanced return false
 * if balanced return true
 */

/* Height Function: Computes the height of a subtree. If any subtree is
unbalanced (-1), or the height difference exceeds 1, it propagates -1 to
indicate imbalance. isBalanced Function: Calls the height function and checks if
the result is not -1.*/

class Solution {
public:
  int height(TreeNode* root) {
    if (root == NULL)
      return 0; // Base case: height of an empty tree is 0

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // If left or right subtree is unbalanced, propagate -1 as a signal
    if (leftHeight == -1 || rightHeight == -1 ||
        abs(leftHeight - rightHeight) > 1)
      return -1;

    // Return height of the tree
    return 1 + max(leftHeight, rightHeight);
  }

  bool isBalanced(TreeNode* root) {
    return height(root) != -1; // A balanced tree won't return -1
  }
};

// Time Complexity: O(n) n-nodes
// Space Complexity: O(h)    h-height of tree

int main() {
  Solution s;

  cout << "Tree 1: " << endl;
  TreeNode* root1 = new TreeNode(3);
  root1->left = new TreeNode(9);
  root1->right = new TreeNode(20);
  root1->right->left = new TreeNode(15);
  root1->right->right = new TreeNode(7);

  cout << (s.isBalanced(root1) ? "Balanced" : "Not Balanced") << endl;

  cout << endl;
  cout << "Tree 2: " << endl;
  TreeNode* root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->right = new TreeNode(2);
  root2->left->left = new TreeNode(3);
  root2->left->right = new TreeNode(3);
  root2->left->left->left = new TreeNode(4);
  root2->left->left->right = new TreeNode(4);

  cout << (s.isBalanced(root2) ? "Balanced" : "Not Balanced") << endl;

  return 0;
}
