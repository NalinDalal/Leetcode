/* 143. Reorder List
You are given the head of a singly linked-list. The list can be represented as:
L0 → L1 → … → Ln - 1 → Ln

Reorder the list to be on the following form:
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

You may not modify the values in the list's nodes. Only nodes themselves may be
changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

Constraints:

The number of nodes in the list is in the range [1, 5 * 10^4].
1 <= Node.val <= 1000*/

// see it is like traverse the linked list
// then try to imitate the reverse pointer for half of ll
// see go through the middle of ll
// then reverse the second half
// after reverseing the second half merge both the new ll

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  void reorderList(ListNode* head) {
    if (!head || !head->next)
      return;

    // Step 1: Find the middle of the linked list
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the list
    ListNode* prev = NULL;
    ListNode* curr = slow;
    ListNode* next;
    while (curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    // Step 3: Merge the two halves
    ListNode* first = head;
    ListNode* second = prev;
    while (second->next) {
      ListNode* temp1 = first->next;
      ListNode* temp2 = second->next;

      first->next = second;
      second->next = temp1;

      first = temp1;
      second = temp2;
    }
  }
};

// Helper function to print the list
void printList(ListNode* head) {
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  // Create example linked list: 1->2->3->4->5
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  cout << "Original list: ";
  printList(head);

  Solution().reorderList(head);

  cout << "Reordered list: ";
  printList(head);

  return 0;
}

/* - Time complexity:
    - Finding the middle takes O(n).
    - Reversing the second half takes O(n).
    - Merging the two halves takes O(n). Thus, the overall time complexity is
O(n), where n is the number of nodes in the list.

- Space complexity:O(1)*/
