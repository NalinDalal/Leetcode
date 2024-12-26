/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/?envType=study-plan-v2&envId=top-interview-150

117. Populating Next Right Pointers in Each Node II
Medium
Topics
Companies
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next
right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.



Example 1:


Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should
populate each next pointer to point to its next right node, just like in Figure
B. The serialized output is in level order as connected by the next pointers,
with '#' signifying the end of each level. Example 2:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 6000].
-100 <= Node.val <= 100


Follow-up:

You may only use constant extra space.
The recursive approach is fine. You may assume implicit stack space does not
count as extra space for this problem.
*/

#include <iostream>
#include <vector>

using namespace std;
// Definition for a Node.
class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

// What to do:
/* 1. Traverse the tree in level order. For each node, if it has a next pointer,
set it to the next right node. If it doesn't have a next pointer, set it to
NuLL.
2. Return the root of the tree.*/

class Solution {
public:
  Node* connect(Node* root) {
    if (root == NULL || root->left == NULL || root->right == NULL)
      return root;
    Node* left = root->left;
    Node* right = root->right;
    root->left = connect(left);
    root->right = connect(right);
    if (root->left->next == NULL)
      root->left->next = root->right;
    if (root->right->next == NULL)
      root->right->next = root->left;
    return root;
  }
};

/* Issues:
1. Unnecessary recursive calls: The recursive calls to connect(left) and
connect(right) are inside the connect method, which causes the tree to be
traversed multiple times, leading to inefficiency.
2. Inefficient connection logic: The connection between the left and right child
nodes (using root->left->next and root->right->next) should happen level by
level, rather than going deep into the tree recursively.*/

// use level-order traversal (BFS)
class Solution1 {
public:
  Node* connect(Node* root) {
    if (!root)
      return root;

    // Start with the root node
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();

      // Iterate through the current level
      for (int i = 0; i < size; ++i) {
        Node* current = q.front();
        q.pop();

        // Connect the next pointer
        if (i < size - 1) {
          current->next = q.front();
        }

        // Add child nodes to the queue
        if (current->left)
          q.push(current->left);
        if (current->right)
          q.push(current->right);
      }
    }

    return root;
  }
};
// O(n)

// Optimised:

class Solution2 {
public:
  Node* connect(Node* root) {
    if (!root)
      return root;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1) {
      Node* curr = q.front();
      q.pop();
      if (!curr) {
        q.push(NULL);
        continue;
      }
      curr->next = q.front();
      if (curr->left)
        q.push(curr->left);
      if (curr->right)
        q.push(curr->right);
    }
    return root;
  }
};
// Time : O(n)
// Space: O(n)
