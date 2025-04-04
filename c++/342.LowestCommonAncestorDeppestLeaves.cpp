/* 1123. Lowest Common Ancestor of Deepest Leaves

Given the root of a binary tree, return the lowest common ancestor of its
deepest leaves.

Recall that:

The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0. if the depth of a node is d, the depth
of each of its children is d + 1. The lowest common ancestor of a set S of
nodes, is the node A with the largest depth such that every node in S is in the
subtree with root A.


Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest leaf-nodes of the tree.
Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but
the depth of nodes 7 and 4 is 3.

Example 2:
Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree, and it's the lca of
itself.

Example 3:
Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest leaf node in the tree is 2, the lca of one node is
itself.


Constraints:
The number of nodes in the tree will be in the range [1, 1000].
0 <= Node.val <= 1000
The values of the nodes in the tree are unique.


Note: This question is the same as 865:
https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
*/
#include <iostream>
#include <utility>
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

/* use a postorder traversal (bottom-up), keeping track of:

Depth of the deepest leaves in the left and right subtrees.

LCA for those deepest leaves.

*/

/* At each node:

Recursively get the depth and LCA from the left and right child.

If both left and right depths are equal ⇒ current node is the LCA.

If left is deeper ⇒ propagate left's LCA.

If right is deeper ⇒ propagate right's LCA.

Apply PostOrder DFS
*/
class Solution {
public:
  TreeNode* lcaDeepestLeaves(TreeNode* root) { return dfs(root).second; }
  pair<int, TreeNode*> dfs(TreeNode* node) {
    if (!node)
      return {0, nullptr};

    auto [leftDepth, leftLCA] = dfs(node->left);
    auto [rightDepth, rightLCA] = dfs(node->right);

    if (leftDepth > rightDepth)
      return {leftDepth + 1, leftLCA};
    if (rightDepth > leftDepth)
      return {rightDepth + 1, rightLCA};
    return {leftDepth + 1, node};
  }
};

// sub:
// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/submissions/1596499326/?envType=daily-question&envId=2025-04-04
// sol:
// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/solutions/6614660/1123-lowest-common-ancestor-of-deepest-l-v4i3/
