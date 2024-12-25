/* https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/?envType=study-plan-v2&envId=top-interview-150
* 106. Construct Binary Tree from Inorder and Postorder Traversal
Medium
Topics
Companies
Given two integer arrays inorder and postorder where inorder is the inorder
traversal of a binary tree and postorder is the postorder traversal of the same
tree, construct and return the binary tree.



Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]


Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.*/

#include <vector>
using std::vector;
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

/*
class Solution {
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    // inorder - left,root,right
    // postorder- left,right,root
    // what we need to do is build a tree from inorder, postorder
    // we need to find the root, and then build the tree from there
    int root = postorder.size() - 1;
    int left = 0;
    int right = root - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (postorder[mid] == inorder[root]) {
        root = mid;
        break;
      }
      if (postorder[mid] > inorder[root]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return root;    //problem: we are returning root(int), but need to return
the
        //TreeNode*

  }
};*/

// problem: vector size returns unsigned integer, but can't be directly bind to
// non-const int& reference
// fix: use int instead of int&
class Solution {
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int postRootIdx = postorder.size() - 1; // Use an `int` to store the index
    return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1,
                           postRootIdx);
  }

private:
  TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder,
                            int inLeft, int inRight, int& postRootIdx) {
    if (inLeft > inRight) {
      return nullptr; // No elements to construct the tree
    }

    // Find the root from postorder (last element in the current range)
    int rootVal = postorder[postRootIdx--];
    TreeNode* root = new TreeNode(rootVal);

    // Find the root in inorder traversal
    int inRootIdx = inLeft;
    while (inorder[inRootIdx] != rootVal) {
      inRootIdx++;
    }

    // Build right and left subtrees (note the order: right first because of
    // postorder traversal)
    root->right = buildTreeHelper(inorder, postorder, inRootIdx + 1, inRight,
                                  postRootIdx);
    root->left =
        buildTreeHelper(inorder, postorder, inLeft, inRootIdx - 1, postRootIdx);

    return root;
  }
};

// Time: O(n)
// Space: O(n)
