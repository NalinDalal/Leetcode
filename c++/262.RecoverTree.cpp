/* 1028. Recover a Tree From Preorder Traversal

We run a preorder depth-first search (DFS) on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this
node), then we output the value of this node.  If the depth of a node is D, the
depth of its immediate child is D + 1.  The depth of the root node is 0.

If a node has only one child, that child is guaranteed to be the left child.

Given the output traversal of this traversal, recover the tree and return its
root.



Example 1:
Input: traversal = "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]

Example 2:
Input: traversal = "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]

Example 3:
Input: traversal = "1-401--349---90--88"
Output: [1,401,null,349,88,90]


Constraints:
The number of nodes in the original tree is in the range [1, 1000].
1 <= Node.val <= 109*/

#include <string>

using std::string;
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
1. Depth determines hierarchy
- A node with depthDis the child of the last node with depthD - 1.
- If a node has a sibling, it appears immediately after its left sibling in the
traversal.
- If a node does not have a sibling, it is the only child of its parent.

2. Maintaining a Structure to Track Parent-Child Relationships
- Using Recursion: We can recursively parse the string and build the tree.
- Using Stack: We maintain a stack where each node is pushed when encountered.
When we process a new node, we find its correct parent by checking the stack for
the most recent node withdepth - 1.
*/

// Approach:
/*
- Start withindex = 0and call the recursivehelperfunction withdepth = 0.

- In `helper` function:

    - If `index` exceeds the length of `traversal`, return `nullptr`.

    - Count the number of dashes (`dashCount`) at `index`:

        - Iterate while the character at `index + dashCount` is '-'.
        - Increase `dashCount` accordingly.
- If `dashCount` does not match `depth`, return `nullptr`(ensures correct tree
structure).

- Move `index` past the dashes.

- Extract the numeric value for the node:
    - Initialize `value = 0`.
    - While `index` points to a digit, update `value` using `value * 10 +
(digit)`.
    - Increment `index` for each digit processed.

- Create a new `TreeNode` with the extracted value.

- Recursively construct left and right children:

    - Call `helper` with `depth + 1` for the left subtree.
    - Call `helper` with `depth + 1` for the right subtree.
- Return the constructed `TreeNode`.

*/

class Solution {
public:
  TreeNode* recoverFromPreorder(string traversal) {
    int index = 0;
    return helper(traversal, index, 0);
  }

private:
  TreeNode* helper(const string& traversal, int& index, int depth) {
    if (index >= traversal.size())
      return nullptr;

    // Count the number of dashes
    int dashCount = 0;
    while (index + dashCount < traversal.size() &&
           traversal[index + dashCount] == '-') {
      dashCount++;
    }

    // If the number of dashes doesn't match the current depth, return null
    if (dashCount != depth)
      return nullptr;

    // Move index past the dashes
    index += dashCount;

    // Extract the node value
    int value = 0;
    while (index < traversal.size() && isdigit(traversal[index])) {
      value = value * 10 + (traversal[index] - '0');
      index++;
    }

    // Create the current node
    TreeNode* node = new TreeNode(value);

    // Recursively build the left and right subtrees
    node->left = helper(traversal, index, depth + 1);
    node->right = helper(traversal, index, depth + 1);

    return node;
  }
};
// sub:
// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/submissions/1551622209/?envType=daily-question&envId=2025-02-22
// sol:
// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/solutions/6454721/1028-recover-a-tree-from-preorder-traver-bg6w/
