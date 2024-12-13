/* 1448. Count Good Nodes in Binary Tree

Given a binary tree root, a node X in the tree is named good if in the path from
root to X there are no nodes with a value greater than X. Return the number of
good nodes in the binary tree.



Example 1:
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.

Example 2:
Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.

Example 3:
Input: root = [1]
Output: 1
Explanation: Root is considered as good.


Constraints:

The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4].
*/

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

// initialise count=0
// apply dfs for each node
// if node is not good, then do nothing
// if node is good, increase the count
// return count
/*
 * class Solution {
public:
  int goodNodes(TreeNode* root) {
    int count = 0;
    if (root == NULL)
      return count;
    dfs(root, count);
    return count;
  }
  void dfs(TreeNode* root, int& count) {
    if (root == NULL)
      return;
    // If the current node's value is greater than or equal to maxSoFar, it's a
    // good node
    if (node->val >= maxSoFar) {
      count++;
    }

    // Update maxSoFar for the children
    int newMax = max(maxSoFar, node->val);

    // Recur for left and right children
    dfs(node->left, count, newMax);
    dfs(node->right, count, newMax);
  }
};
*/
// problem:
/*1. Null Pointer Dereference:
You're accessing root->left->val and root->right->val without checking if
root->left or root->right is NULL. This can cause a runtime error.

2. Incorrect Logic:
The problem likely expects you to count "good nodes," which are nodes whose
value is greater than or equal to all values in the path from the root to that
node. The condition root->val > root->left->val && root->val > root->right->val
does not align with this.
*/
// updated solution:
class Solution {
public:
  int goodNodes(TreeNode* root) {
    int count = 0;
    if (root == NULL)
      return count;
    dfs(root, count, root->val);
    return count;
  }
  void dfs(TreeNode* node, int& count, int maxSoFar) {
    if (node == NULL)
      return;
    // If the current node's value is greater than or equal to maxSoFar, it's a
    // good node
    if (node->val >= maxSoFar) {
      count++;
    }

    // Update maxSoFar for the children
    int newMax = max(maxSoFar, node->val);

    // Recur for left and right children
    dfs(node->left, count, newMax);
    dfs(node->right, count, newMax);
  }
};

// optimised:
/*1. Eliminate count Parameter:
Instead of passing a reference parameter for count, the dfs function now
directly returns the count of good nodes in the subtree. This simplifies the
function signature.

2. Simplify Base Case:
The check for node == NULL is combined into a single return statement, which
returns 0 for null nodes.

3. Avoid Recomputing maxSoFar:
Update maxSoFar directly in the recursive call, avoiding the need for an
additional variable newMax.
*/

class Solution1 {
public:
  int goodNodes(TreeNode* root) { return dfs(root, root->val); }

private:
  int dfs(TreeNode* node, int maxSoFar) {
    if (!node)
      return 0;

    // Count the current node as good if it meets the criteria
    int count = (node->val >= maxSoFar) ? 1 : 0;

    // Update the maximum value seen so far
    maxSoFar = max(maxSoFar, node->val);

    // Accumulate good nodes from left and right subtrees
    count += dfs(node->left, maxSoFar);
    count += dfs(node->right, maxSoFar);

    return count;
  }
};

// Time Complexity: 𝑂(𝑁) as each node is visited exactly once.

// Space Complexity: 𝑂(𝐻), due to the recursion stack, where 𝐻 is the height of
// the tree. In the worst case (skewed tree), 𝐻=𝑁; in the best case (balanced
// tree), 𝐻=log𝑁.

int main() {
  Solution1 s;
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(3);
  root->right->right = new TreeNode(2);

  cout << s.goodNodes(root) << endl;
  return 0;
}
