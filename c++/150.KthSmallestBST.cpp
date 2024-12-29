/* 230. Kth Smallest Element in a BST
Given the root of a binary search tree, and an integer k, return the kth
smallest value (1-indexed) of all the values of the nodes in the tree.



Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3


Constraints:
The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104


Follow up: If the BST is modified often (i.e., we can do insert and delete
operations) and you need to find the kth smallest frequently, how would you
optimize?*/

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

// to return kth smallest element in BST
//  1. BST is given
//  2. traverse the tree BSF wise from leaf nodes and return the kth item

class Solution {
public:
  int count = 0;   // Keeps track of the number of nodes visited
  int result = -1; // Holds the value of the k-th smallest node

  void inorder(TreeNode* root, int k) {
    if (root == nullptr)
      return;

    // Traverse left subtree
    inorder(root->left, k);

    // Increment the count for each node visited
    count++;

    // If count matches k, set the result
    if (count == k) {
      result = root->val;
      return; // No need to continue the traversal once we find the result
    }

    // Traverse right subtree
    inorder(root->right, k);
  }

  int kthSmallest(TreeNode* root, int k) {
    inorder(root, k);
    return result; // Return the k-th smallest value
  }
};

// We were trying to traverse the tree using a variant of a Breadth-First Search
// (BFS), but the approach is more suited for an in-order traversal in a BST,
// which is known to visit elements in ascending order.
// 100%

/* - Time complexity: $$O(H+K)$$
$$H- height of tree$$
$$k- given no of nodes$$

- Space complexity: $$O(H)$$*/

// submission:
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/1491234752/
// solution:
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/solutions/6199660/230-kth-smallest-element-in-a-bst100-by-4vh1i/
