/* 199. Binary Tree Right Side View

Given the root of a binary tree, imagine yourself standing on the right side of
it, return the values of the nodes you can see ordered from top to bottom.



Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]


Example 2:
Input: root = [1,2,3,4,null,null,null,5]
Output: [1,3,4,5]


Example 3:
Input: root = [1,null,3]
Output: [1,3]


Example 4:
Input: root = []
Output: []



Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100 */

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
// if right node is present move towards it
// else move towards the left node
// log nodes at each level dfs

//
// Helper function to create tree from vector
TreeNode* createBinaryTree(const vector<int>& arr) {
  if (arr.empty())
    return nullptr;

  // Create root node
  TreeNode* root = new TreeNode(arr[0]);

  // Use a queue to track nodes for which we need to assign children
  queue<TreeNode*> nodeQueue;
  nodeQueue.push(root);

  // Index to track current position in the input array
  int i = 1;

  while (!nodeQueue.empty() && i < arr.size()) {
    TreeNode* current = nodeQueue.front();
    nodeQueue.pop();

    // Check and assign left child
    if (i < arr.size() && arr[i] != -1) {
      current->left = new TreeNode(arr[i]);
      nodeQueue.push(current->left);
    }
    i++;

    // Check and assign right child
    if (i < arr.size() && arr[i] != -1) {
      current->right = new TreeNode(arr[i]);
      nodeQueue.push(current->right);
    }
    i++;
  }

  return root;
}

// Helper function to print the tree (level-order traversal)
void printTree(TreeNode* root) {
  if (!root) {
    cout << "Empty tree" << endl;
    return;
  }

  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    int levelSize = q.size();
    for (int i = 0; i < levelSize; ++i) {
      TreeNode* node = q.front();
      q.pop();

      if (node) {
        cout << node->val << " ";
        q.push(node->left);
        q.push(node->right);
      } else {
        cout << "null ";
      }
    }
    cout << endl;
  }
}
//
// Helper function to free memory
void deleteTree(TreeNode* root) {
  if (root == nullptr)
    return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}
//
// wrong one, but u get the idea
class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if (root == nullptr)
      return ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        TreeNode* node = q.front();
        q.pop();
        if (node->right != nullptr) {
          q.push(node->right);
          ans.push_back(node->right->val);
        }
        if (node->left != nullptr) {
          q.push(node->left);
          ans.push_back(node->left->val);
        }
      }
    }
    return ans;
  }
};

/* Code Idea :
Perform a level-order traversal of the tree (BFS).
At each level, add the last node encountered to the result since it is the
rightmost node visible from that level. Alternatively, use DFS to traverse the
tree, prioritizing the right subtree.
*/

/* Algorithm :
BFS Approach :
Use a queue to perform level-order traversal of the tree.
For each level, keep track of the last node in the queue (rightmost node for
that level). Append the value of the rightmost node to the result. DFS Approach
: Use a recursive DFS, visiting the right subtree first. Track the depth of the
traversal and add the first node encountered at each depth to the result. */

// Steps:
/* 1. BFS Steps :
Initialize an empty queue and result list.
Traverse the tree level by level using the queue.
At each level, add the last node in the queue to the result.

2. DFS Steps :
Use recursion to traverse the tree.
Prioritize the right subtree over the left.
Add the first node encountered at each depth to the result.
*/

// BFS Approach takesoumen collection
class Solution2 {
public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (!root)
      return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int levelSize = q.size();
      for (int i = 0; i < levelSize; ++i) {
        TreeNode* node = q.front();
        q.pop();

        if (i == levelSize - 1)
          result.push_back(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
    }

    return result;
  }
};

// Time Complexity: O(n) {every node is visited once}
// Space Complexity:
// BFS: O(w), where w is the maximum width of the tree.
// DFS: O(h), where h is the height of the tree (for recursion stack).
// 100%

int main() {
  vector<int> root1 = {1, 2, 3, null, 5, null, 4};
  vector<int> root2 = {1, 2, 3, 4, null, null, null, 5};
  TreeNode* root1 = createBinaryTree(root1);
  TreeNode* root2 = createBinaryTree(root2);
  // Print the tree to verify
  printTree(root1);
  printTree(root2);

  Solution2 s;
  vector<int> ans1 = s.rightSideView(root1);
  cout << "Tree 1:";
  for (int i = 0; i < ans1.size(); i++) {
    cout << ans1[i] << " ";
  }

  vector<int> ans2 = s.rightSideView(root2);
  cout << "Tree 2:";
  for (int i = 0; i < ans2.size(); i++) {
    cout << ans2[i] << " ";
  }
  // Don't forget to free memory
  deleteTree(root1);
  deleteTree(root2);
  return 0;
}
