/*543. Diameter of Binary Tree

Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two
nodes in a tree. This path may or may not pass through the root. The length of a
path between two nodes is represented by the number of edges between them.



Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1


Constraints:
The number of nodes in the tree is in the range [1, 10^4].
-100 <= Node.val <= 100*/

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

// intuition:
// if the node is leaf itself, then return 0
// if the node is not leaf, then return the max of left and right diameter
// now to get the diameter, we need to do a DFS
// at each node we have to check if current node is leaf or not
// if it is leat, then return o
// if it is not leaf, then we need to check if the current node is the root or
// not if it is the root, then we need to check if the current node is left or
// right child if it is left child, then we need to check if the current node is
// the root or not if it is right child, then we need to check if the current
// node is the root or not if it is the root, then we need to check if the
// current node is left or right child if it is left child, then we need to
// check if the current node is the root or not if it is right child, then we
// need to check if the current node is the root or not

class Solution {
public:
  int diameterOfBinaryTree(TreeNode* root) {
    if (root == NULL)
      return 0;
    if (root->left == NULL && root->right == NULL)
      return 0;

    int left_diameter = diameterOfBinaryTree(root->left);

    int right_diameter = diameterOfBinaryTree(root->right);

    if (root->left != NULL && root->right != NULL)
      return max(left_diameter, right_diameter) + 1;

    return max(left_diameter, right_diameter);
  }
};

// Approach:
/* 1. Use a helper function to compute the height of the tree while also
updating the diameter.
2. At each node, compute the diameter as the sum of the heights of its left and
right subtrees.
3. Keep track of the maximum diameter using a class variable or a reference
parameter.*/
/* Function diameterOfBinaryTree(node):
    Initialize diameter = 0

    Function height(node):
        if node == NULL:
            return 0

        left_height = height(node.left)
        right_height = height(node.right)

        # Update the diameter at this node
        diameter = max(diameter, left_height + right_height)

        # Return the height of the current subtree
        return 1 + max(left_height, right_height)

    height(root)
    Return diameter
*/

class Solution1 {
public:
  int diameter = 0;

  int height(TreeNode* root) {
    if (root == NULL)
      return 0;

    int left_height = height(root->left);
    int right_height = height(root->right);

    // Update the diameter at the current node
    diameter = max(diameter, left_height + right_height);

    // Return the height of the subtree rooted at this node
    return 1 + max(left_height, right_height);
  }

  int diameterOfBinaryTree(TreeNode* root) {
    height(root); // This function updates the diameter
    return diameter;
  }
};

int main() {
  cout << "Test Case 1: " << endl;
  TreeNode* root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(3);
  root1->left->left = new TreeNode(4);
  root1->left->right = new TreeNode(5);
  Solution1 obj;
  int ans = obj.diameterOfBinaryTree(TreeNode * root1);
  cout << ans << endl;

  cout << "Test Case 2: " << endl;
  TreeNode* root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  Solution1 obj1;
  int ans1 = obj1.diameterOfBinaryTree(TreeNode * root2);
  cout << ans1 << endl;
  return 0;
}

// Space Complexity : 𝑂(ℎ);h is height of the tree
// Time Complexity : 𝑂(𝑛); n is the number of node
