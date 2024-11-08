/*138. Copy List with Random Pointer

A linked list of length n is given such that each node contains an additional
random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n
brand new nodes, where each new node has its value set to the value of its
corresponding original node. Both the next and random pointer of the new nodes
should point to new nodes in the copied list such that the pointers in the
original list and copied list represent the same list state. None of the
pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random
--> Y, then for the corresponding two nodes x and y in the copied list, x.random
--> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each
node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random
pointer points to, or null if it does not point to any node. Your code will only
be given the head of the original linked list.

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
*/

// well what i can deduce is that, given a ll, create a ll which is exact copy
// of the given ll

// Hint 1
// Just iterate the linked list and create copies of the nodes on the go. Since
// a node can be referenced from multiple nodes due to the random pointers,
// ensure you are not making multiple copies of the same node.

// Strategy
/*Iterate through the original list and for each node, create a new node.
However, if you encounter a node that's already been copied (because of the
random pointer), reuse the copied node instead of creating a new one. This
avoids making multiple copies of the same node. You can use a hash map
(dictionary) to store references from the original node to the copied node,
which will help with tracking already created nodes.*/

// Steps
/*1. Traverse the original list and create new nodes for each original node's
next pointer.
2. Store the original node as the key and the newly created node as the value in
a map (hash map) to ensure that if the node is referenced again, you can reuse
the copy.
3. For each node, after copying the next pointer, set up the random pointer by
looking up the corresponding copy in the map.*/

#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

// Definition for a Node.
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (!head) {
      return nullptr;
    }
    // std::unordered_map<std::string, int> oldToNew; // hashmap intialised
    std::unordered_map<Node *, Node *> oldToNew;

    /*# First pass: Create all the new nodes without random/next pointers
current = head
while current:
    old_to_new[current] = Node(current.val)
    current = current.next
    */
    Node *current = head;
    while (current != nullptr) {
      // old_to_new
      oldToNew[current] = new Node(current->val);
      current = current->next;
    }

    /*
        # Second pass: Set the next and random pointers
        current = head
        while current:
            if current.next:
                old_to_new[current].next = old_to_new[current.next]
            if current.random:
                old_to_new[current].random = old_to_new[current.random]
            current = current.next

        return old_to_new[head]
                */
    current = head;

    while (current != nullptr) {
      if (current->next) {
        oldToNew[current]->next = oldToNew[current->next];
      }
      if (current->random) {
        oldToNew[current]->random = oldToNew[current->random];
      }
      current = current->next;
    }

    // Return the head of the new copied list
    return oldToNew[head];
  }
  // solution ends here, now for test cases will be the logic->
};

// Helper function to create a list from a vector of pairs
Node *createList(const std::vector<std::pair<int, int>> &nodeData) {
  std::vector<Node *> nodes;
  for (const auto &data : nodeData) {
    nodes.push_back(new Node(data.first));
  }
  for (int i = 0; i < nodeData.size(); ++i) {
    if (i < nodeData.size() - 1) {
      nodes[i]->next = nodes[i + 1];
    }
    if (nodeData[i].second != -1) {
      nodes[i]->random = nodes[nodeData[i].second];
    }
  }
  return nodes.empty() ? nullptr : nodes[0];
}

// Helper function to verify that the copied list matches the expected structure
bool listsEqual(Node *original, Node *copy) {
  while (original && copy) {
    if (original->val != copy->val) {
      return false;
    }
    if ((original->random && !copy->random) ||
        (!original->random && copy->random)) {
      return false;
    }
    if (original->random && copy->random &&
        original->random->val != copy->random->val) {
      return false;
    }
    original = original->next;
    copy = copy->next;
  }
  return !original && !copy;
}

// Test case 1: [[7,null],[13,0],[11,4],[10,2],[1,0]]
void test1() {
  std::vector<std::pair<int, int>> nodeData = {
      {7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}};
  Node *head = createList(nodeData);

  Solution solution;
  Node *copiedList = solution.copyRandomList(head);

  assert(listsEqual(head, copiedList));
  std::cout << "Test case 1 passed!" << std::endl;
}

// Test case 2: [[1,1],[2,1]]
void test2() {
  std::vector<std::pair<int, int>> nodeData = {{1, 1}, {2, 1}};
  Node *head = createList(nodeData);

  Solution solution;
  Node *copiedList = solution.copyRandomList(head);

  assert(listsEqual(head, copiedList));
  std::cout << "Test case 2 passed!" << std::endl;
}

// Test case 3: [[3,null],[3,0],[3,null]]
void test3() {
  std::vector<std::pair<int, int>> nodeData = {{3, -1}, {3, 0}, {3, -1}};
  Node *head = createList(nodeData);

  Solution solution;
  Node *copiedList = solution.copyRandomList(head);

  assert(listsEqual(head, copiedList));
  std::cout << "Test case 3 passed!" << std::endl;
}

int main() {
  test1();
  test2();
  test3();
  std::cout << "All test cases passed!" << std::endl;
  return 0;
}
// Time Complexity:O(n)
// Space Complexity:O(n)
