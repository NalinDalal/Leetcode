/* 572. Subtree of Another Tree

Given the roots of two binary trees root and subRoot, return true if there is a
subtree of root with the same structure and node values of subRoot and false
otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and
all of this node's descendants. The tree tree could also be considered as a
subtree of itself.


Example 1:
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

Example 2:
Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false


Constraints:
The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-104 <= root.val <= 104
-104 <= subRoot.val <= 104 */
#include <iostream>
#include <queue>
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

// what to do:
// 1. if root or subroot is null, return false
// 2. if root and subroot have same value, return true
// 3. if root and subroot have different values, check if subroot is a subtree
// of root
// 4. if subroot is a subtree of root, return true
// 5. if subroot is not a subtree of root, return false
class Solution {
public:
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr || subRoot == nullptr)
      return false;
    if (root->val == subRoot->val)
      return true;
    if (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot))
      return true;
    return false;
    return isSubtree(root->left, subRoot) | isSubtree(root->right, subRoot);
  }
};

// issues:
/* Incorrect Base Case:
If subRoot is nullptr, the function should return true because an empty tree is
always a subtree of any tree. If root is nullptr and subRoot is not, the
function should return false because a non-empty subtree cannot exist in an
empty tree.

Incorrect Matching Condition:
When root->val == subRoot->val, the function immediately returns true, which is
incorrect. It should instead verify that the entire structure of subRoot matches
a part of root.

Redundant Return Statements:
The line return isSubtree(root->left, subRoot) | isSubtree(root->right,
subRoot); is unreachable because earlier return statements always terminate the
function.*/

// fixes:
/* 1. Implement a helper function, isSameTree(TreeNode* root1, TreeNode* root2),
that checks if two trees are identical.
2. Use isSameTree in the main function to verify if subRoot is identical to the
current subtree of root.
3. Recursively check the left and right subtrees of root.*/

class Solution1 {
public:
  bool isSameTree(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2)
      return true; // Both trees are null
    if (!root1 || !root2)
      return false; // One tree is null, the other is not
    if (root1->val != root2->val)
      return false; // Values don't match

    // Recursively check left and right subtrees
    return isSameTree(root1->left, root2->left) &&
           isSameTree(root1->right, root2->right);
  }

  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!subRoot)
      return true; // An empty tree is always a subtree
    if (!root)
      return false; // A non-empty tree can't be a subtree of an empty tree

    // Check if the current trees are identical or recurse on left/right subtree
    return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
  }
};

// Time complexity: 𝑂(𝑛×𝑚)  {n =number of nodes in the root tree, m = number of
// nodes in the subRoot trees} Space complexity: O(max(d1,d2)), where 𝑑1 and 𝑑2
// are the depths of root and subRoot.
// Space complexity: $$O(d)$$ d-depth

// Helper function to build a binary tree from a vector
TreeNode* buildTree(const vector<int>& values) {
  if (values.empty() || values[0] == -1)
    return nullptr;

  TreeNode* root = new TreeNode(values[0]);
  queue<TreeNode*> q;
  q.push(root);

  int i = 1;
  while (i < values.size()) {
    TreeNode* current = q.front();
    q.pop();

    if (values[i] != -1) {
      current->left = new TreeNode(values[i]);
      q.push(current->left);
    }
    i++;

    if (i < values.size() && values[i] != -1) {
      current->right = new TreeNode(values[i]);
      q.push(current->right);
    }
    i++;
  }

  return root;
}

// Helper function to delete a tree and free memory
void deleteTree(TreeNode* root) {
  if (!root)
    return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

int main() {
  Solution sol;

  // Test Case 1
  vector<int> root1Values = {3, 4, 5, 1, 2};
  vector<int> subRoot1Values = {4, 1, 2};
  TreeNode* root1 = buildTree(root1Values);
  TreeNode* subRoot1 = buildTree(subRoot1Values);
  cout << (sol.isSubtree(root1, subRoot1) ? "true" : "false") << endl;
  deleteTree(root1);
  deleteTree(subRoot1);

  // Test Case 2
  vector<int> root2Values = {3, 4, 5, 1, 2, -1, -1, -1, -1, 0};
  vector<int> subRoot2Values = {4, 1, 2};
  TreeNode* root2 = buildTree(root2Values);
  TreeNode* subRoot2 = buildTree(subRoot2Values);
  cout << (sol.isSubtree(root2, subRoot2) ? "true" : "false") << endl;
  deleteTree(root2);
  deleteTree(subRoot2);

  return 0;
}

// 100%
