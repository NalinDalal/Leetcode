/*104. Maximum Depth of Binary Tree

Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from
the root node down to the farthest leaf node.


Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:
Input: root = [1,null,2]
Output: 2


Constraints:
The number of nodes in the tree is in the range [0, 10^4].
-100 <= Node.val <= 100*/

#include <iostream>
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

class Solution {
public:
  int maxDepth(TreeNode* root) {
    if (root == nullptr)
      return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + max(l, r);
  }
};

int main() {
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(9);

  root->right = new TreeNode(20);
  root->left->left = new TreeNode(15);
  root->left->right = new TreeNode(7);
  root->right->left = nullptr;
  root->right->right = nullptr;
  Solution sol;
  cout << sol.maxDepth(root) << endl;
  return 0;
}

// well the tree is populated in breadth first order
// so max depth is number of nodes=2^d-1 {d is depth}
// return max depth
//
// well what if tree is empty:
// return 0
// recursion:
// 1+max(l,r)
// l,r are subtrees nodes; so this way it will call again and again till the
// leaf nodes and then will again trace back to root node with max(l,r) at each
// step

// 100% score
//  time complexity: O(n)
//  space complexity: O(log n)
