/* 25. Reverse Nodes in k-Group

Given the head of a linked list, reverse the nodes of the list k at a time, and
return the modified list. k is a positive integer and is less than or equal to
the length of the linked list. If the number of nodes is not a multiple of k
then left-out nodes, in the end, should remain as it is. You may not alter the
values in the list's nodes, only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
1->2->3->4->5
    ||
2->1->4->3->5

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]


Constraints:
The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000

Follow-up: Can you solve the problem in O(1) extra memory space?*/

// Anything->
/*well what if we sort of group them and reverse the group
obviously given that size of group is k
We need to reverse the linked list in groups of k nodes
if size<k -> leave as it
The problem restricts us from altering the node values, so we must change the
pointers, what i though initially
 - We must reverse every group of k nodes.
 - If the number of nodes left is less than k, we should keep them unchanged.
 - We want to solve this with constant extra space (in-place operations).*/

// Approach
/*Traverse and Count:
First, traverse the list to ensure that there are at least k nodes remaining. If
not, terminate the reversal and return the list as it is.

Reverse in Chunks:
For each valid group of k nodes:
Reverse the pointers of the nodes within the group.
Keep track of the previous group's tail and the next node (to maintain the
connection with the next part of the list). Continue this process until fewer
than k nodes are left.

Handle Edge Cases:
If k equals 1, no reversal is needed.
If the list is empty, return nullptr. */

#include <iostream>
using namespace std;

// Definition for singly-linked list.

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Helper function to reverse a section of the linked list
ListNode *reverse(ListNode *start, ListNode *end) {
  ListNode *prev = nullptr;
  ListNode *curr = start;
  ListNode *next = nullptr;

  while (curr != end) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev; // new head of the reversed section
}

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head || k == 1)
      return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *prevGroupEnd = dummy;

    while (true) {
      ListNode *groupStart = prevGroupEnd->next;
      ListNode *groupEnd = prevGroupEnd;

      // Check if there are at least k nodes left
      for (int i = 0; i < k && groupEnd; ++i) {
        groupEnd = groupEnd->next;
      }
      if (!groupEnd)
        break; // Less than k nodes remaining

      // Reverse the k nodes
      ListNode *nextGroupStart = groupEnd->next;
      ListNode *newGroupHead = reverse(groupStart, groupEnd->next);

      // Connect the previous group with the reversed group
      prevGroupEnd->next = newGroupHead;
      groupStart->next = nextGroupStart;

      // Move prevGroupEnd to the end of the reversed group
      prevGroupEnd = groupStart;
    }

    return dummy->next;
  }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

// Helper function to create a linked list from an array
ListNode *createLinkedList(const vector<int> &vals) {
  if (vals.empty())
    return nullptr;
  ListNode *head = new ListNode(vals[0]);
  ListNode *current = head;
  for (size_t i = 1; i < vals.size(); ++i) {
    current->next = new ListNode(vals[i]);
    current = current->next;
  }
  return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode *head) {
  ListNode *current = head;
  while (current) {
    cout << current->val;
    if (current->next)
      cout << " -> ";
    current = current->next;
  }
  cout << endl;
}

int main() {
  Solution solution;

  // Test Case 1
  vector<int> values1 = {1, 2, 3, 4, 5};
  int k1 = 2;
  ListNode *head1 = createLinkedList(values1);
  cout << "Original List 1: ";
  printLinkedList(head1);
  ListNode *result1 = solution.reverseKGroup(head1, k1);
  cout << "Reversed List (k = 2): ";
  printLinkedList(result1);

  // Test Case 2
  vector<int> values2 = {1, 2, 3, 4, 5};
  int k2 = 3;
  ListNode *head2 = createLinkedList(values2);
  cout << "Original List 2: ";
  printLinkedList(head2);
  ListNode *result2 = solution.reverseKGroup(head2, k2);
  cout << "Reversed List (k = 3): ";
  printLinkedList(result2);

  return 0;
}
