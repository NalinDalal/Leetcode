/* 82. Remove Duplicates from Sorted List II

Given the head of a sorted linked list, delete all nodes that have duplicate
numbers, leaving only distinct numbers from the original list. Return the linked
list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]


Constraints:
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.*/

#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *prev = nullptr;
    while (head != nullptr & head->next != nullptr) {
      if (head->val = head->next->val) {
        prev->next = head->next->next;
        delete head;
        head = prev->next;
      }
    }
    return head;
  }
};
*/
// run time error
//  to delete all instances of a node which has a duplicate value, we need to
//  traverse the list and keep track of previous nodes. if new traversed node
//  has a duplicate value, we need to delete that node, previous node and set
//  the next pointer of previous->previous node to next node. if new traversed
//  node has a unique value, we need to set the next pointer of previous node to
//  next node.

// Time Complexity: O(n)
// Space Complexity: O(1)

/* Issues:
1. prev is not updated: In the given code, prev is initialized to nullptr but is
never updated, leading to undefined behavior when accessing prev->next.
2. Condition in the while loop is incorrect: The loop checks head != nullptr &
head->next != nullptr, which uses a single & instead of the logical &&. The
single & is a bitwise operator, not a logical operator.
3. The return value is incorrect: After the duplicates are removed, the code
returns head. However, head is updated during the iteration and may not point to
the start of the list.*/

/*
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return nullptr; // Handle empty list

        ListNode *current = head; // Pointer to iterate through the list
        while (current && current->next) {
            if (current->val == current->next->val) {
                ListNode *temp = current->next; // Store the duplicate node
                current->next = current->next->next; // Remove the duplicate
                delete temp; // Free memory
            } else {
                current = current->next; // Move to the next node
            }
        }

        return head; // Return the head of the updated list
    }
};*/

// remove all nodes that have duplicates, not just the duplicate instances
// themselves, the solution needs to be adjusted. Here's how we can modify the
// implementation to achieve this:

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    // Create a dummy node to handle edge cases (e.g., duplicates at the head)
    ListNode *dummy = new ListNode(0, head);
    ListNode *prev = dummy; // Pointer to the last node known to be unique

    while (head) {
      // Check if the current node is a duplicate
      if (head->next && head->val == head->next->val) {
        // Skip all nodes with the same value
        while (head->next && head->val == head->next->val) {
          ListNode *temp = head;
          head = head->next;
          delete temp; // Free memory for skipped nodes
        }
        // Remove the last duplicate node
        prev->next = head->next;
        delete head;       // Free memory for the last duplicate
        head = prev->next; // Move head to the next distinct node
      } else {
        // If no duplicate, just move forward
        prev = head;
        head = head->next;
      }
    }

    ListNode *result = dummy->next;
    delete dummy; // Free the dummy node
    return result;
  }
};
