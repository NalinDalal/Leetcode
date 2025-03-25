/*108. Convert Sorted Array to Binary Search Tree

Given an integer array nums where the elements are sorted in ascending order,
convert it to a height-balanced binary search tree.

Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:
Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.


Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.
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

// convert BST to AVl Tree
// start with arr 0th index, put it at root
// now move forward, when you encounter no less than root, put at left
// child
//  greater than root -> right child,
//  check recursively for subtree also
//  return root
/* Wrong Code
 if (nums.size() == 0)
      return nullptr;

    TreeNode* root = new TreeNode(nums[0]);
    TreeNode* curr = root;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] >= curr->val) {
        curr->right = new TreeNode(nums[i]);
        curr = curr->right;
      } else {
        curr->left = new TreeNode(nums[i]);
        curr = curr->left;
      }
    }

    return root;*/

/* 1. If the array is empty, return null.
2. Find the middle element of the array and create a new node with its value.
3. Recursively construct the left subtree using the left half of the array.
3. Recursively construct the right subtree using the right half of the array.
4. Set the left and right child of the node created in step 2 to the root of the
left and right subtree respectively.
5. Return the root node.*/

/* algo:
- initialize start=0 and end=(length of array -1)
- call recursive method : createTree(nums,start,end)
    - if start>end return NULL
    - calculate mid=(start+end)/2
    - create Node(Root) with nums[mid] as value
    - node.left = createTree(nums,0,mid-1)
    - node.right = createTree(nums,mid+1,end)
 return node
*/
class Solution {

public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {}
};
