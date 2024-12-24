/*  173. Binary Search Tree Iterator

Implement the BSTIterator class that represents an iterator over the in-order
traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The
root of the BST is given as part of the constructor. The pointer should be
initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the
right of the pointer, otherwise returns false. int next() Moves the pointer to
the right, then returns the number at the pointer. Notice that by initializing
the pointer to a non-existent smallest number, the first call to next() will
return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at
least a next number in the in-order traversal when next() is called.



Example 1:

Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext",
"next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False


Constraints:
The number of nodes in the tree is in the range [1, 105].
0 <= Node.val <= 106
At most 105 calls will be made to hasNext, and next.


Follow up:

Could you implement next() and hasNext() to run in average O(1) time and use
O(h) memory, where h is the height of the tree?*/
// Definition for a binary tree node.

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// just do what is asked:
/* 1. initialise the pointer to a non-existent smallest number
 * 2. move the pointer to the right, increase the number at the pointer., return
 * it*/

class BSTIterator {
private:
  stack<TreeNode*> stk;

public:
  BSTIterator(TreeNode* root) {
    // Traverse the tree and push all the left nodes onto the stack
    while (root != nullptr) {
      stk.push(root);
      root = root->left;
    }
  }

  int next() {
    // The next smallest element is the top of the stack
    TreeNode* node = stk.top();
    stk.pop();

    // After popping, if the node has a right child, push all the left nodes of
    // that child onto the stack
    TreeNode* right = node->right;
    while (right != nullptr) {
      stk.push(right);
      right = right->left;
    }

    return node->val;
  }

  bool hasNext() {
    // If the stack is not empty, there are more elements
    return !stk.empty();
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

// Helper function to build the binary tree from an array
TreeNode* buildTree(const vector<int>& values, int index = 0) {
  if (index >= values.size() || values[index] == NULL)
    return nullptr;
  TreeNode* root = new TreeNode(values[index]);
  root->left = buildTree(values, 2 * index + 1);
  root->right = buildTree(values, 2 * index + 2);
  return root;
}

int main() {

  // Input: array representing the binary tree
  // vector<int> values = {7, 3, 15, nullptr, nullptr, 9, 20};
  // replace nullptr with -1 to make it work
  vector<int> values = {7, 3, 15, -1, -1, 9, 20};
  // Build the tree
  TreeNode* root = buildTree(values);

  // Instantiate the BSTIterator
  BSTIterator* obj = new BSTIterator(root);

  // Output the results
  cout << "Next values: ";
  while (obj->hasNext()) {
    cout << obj->next() << " ";
  }
  cout << endl;

  return 0;
}

// Time Complexity: O(h); h=height of tree
// Space Complexity: O(h);
// 54.06%
