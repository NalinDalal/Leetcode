/* 889. Construct Binary Tree from Preorder and Postorder Traversal
Medium
Topics
Companies
Given two integer arrays, preorder and postorder where preorder is the preorder
traversal of a binary tree of distinct values and postorder is the postorder
traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.



Example 1:


Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
Example 2:

Input: preorder = [1], postorder = [1]
Output: [1]


Constraints:

1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
All the values of preorder are unique.
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
All the values of postorder are unique.
It is guaranteed that preorder and postorder are the preorder traversal and
postorder traversal of the same binary tree.
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

class Solution {
public:
  // given preorder and postorder
  // return tree in bfs
  // preorder: root,left,right
  // postorder:left,right,root

  // Global index for preorder traversal
  int preIndex = 0;
  // Recursive helper function to construct tree.
  // 'postStart' and 'postEnd' define the current segment of the postorder
  // vector.
  TreeNode* constructTree(const vector<int>& pre, const vector<int>& post,
                          int postStart, int postEnd) {
    // Base case: if there are no elements to process, return nullptr.
    if (preIndex >= pre.size() || postStart > postEnd)
      return nullptr;

    // Create the root node with the current element in preorder.
    TreeNode* root = new TreeNode(pre[preIndex++]);

    // If the current segment has only one element, it is a leaf node.
    if (postStart == postEnd)
      return root;

    // The next element in preorder is the left child.
    // Find that element in the postorder vector to determine the left subtree
    // boundary.
    int leftSubtreeRootVal = pre[preIndex];
    int postIndex = postStart;
    while (postIndex <= postEnd && post[postIndex] != leftSubtreeRootVal) {
      postIndex++;
    }

    // Recursively construct the left subtree using the portion [postStart,
    // postIndex]
    root->left = constructTree(pre, post, postStart, postIndex);

    // Recursively construct the right subtree using the remaining part.
    // Note: postIndex+1 to postEnd-1 because post[postEnd] is the current root.
    root->right = constructTree(pre, post, postIndex + 1, postEnd - 1);

    return root;
  }

public:
  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    preIndex = 0; // initialize the global preorder index
    return constructTree(pre, post, 0, post.size() - 1);
  }
};
// time: O(n)
// space: O(n)

/* Approach:
1. TreeNode Structure: A simple struct defines the binary tree node.

2. Recursive Construction (constructTree):
- The root is created from the current element in the preorder vector (tracked
by preIndex).
- If the current subtree contains a single node, return the node.
- Otherwise, the next value in preorder is the root of the left subtree. We find
this value in the postorder segment to determine the boundary of the left
subtree.
- Recursively construct the left subtree using the portion from postStart to the
found index.
- Construct the right subtree using the remaining postorder segment (excluding
the last element which is the root).
3. `constructFromPrePost`:
- Initializes the global preorder index and calls the recursive helper.
*/

// sub:
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/submissions/1552566421/?envType=daily-question&envId=2025-02-23
// sol:
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/solutions/6458117/889-construct-binary-tree-from-preorder-vuq7g/
