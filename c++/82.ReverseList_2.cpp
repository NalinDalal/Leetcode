/* 92. Reverse Linked List II

Given the head of a singly linked list and two integers left and right where
left <= right, reverse the nodes of the list from position left to position
right, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]


Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n */

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Approach :
/* Traverse the list to find the starting position (left).
Reverse the nodes between left and right.
Reconnect the reversed sublist with the rest of the list.*/

class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right)
      return head; // No reversal needed

    // Create a dummy node to simplify edge cases
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;

    // Step 1: Traverse to the node before `left`
    for (int i = 1; i < left; ++i) {
      prev = prev->next;
    }

    // Step 2: Reverse the sublist
    ListNode* curr = prev->next;
    ListNode* next = nullptr;
    ListNode* sublist_tail = curr;
    for (int i = left; i <= right; ++i) {
      next = curr->next;
      curr->next = prev->next;
      prev->next = curr;
      curr = next;
    }

    // Step 3: Reconnect the reversed sublist with the rest of the list
    sublist_tail->next = curr;

    return dummy->next;
  }
};

/* # Complexity
- Time complexity:O(n)

- Space complexity:O(n)*/
