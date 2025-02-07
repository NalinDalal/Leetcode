/* https://leetcode.com/problems/sort-list/description/
148. Sort List

Given the head of a linked list, return the list after sorting it in ascending
order.


Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:
Input: head = []
Output: []


Constraints:
The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
*/
/* Intuition
sort the linkedlist in ascending order
Apply Top Down Merge Sort*/

/* # Approach
1. Base Case Handling: Ensure that the base case (when the list has one or zero
elements) is handled correctly. Your current check if (head == nullptr ||
head->next == nullptr) is correct for the base case.

2. Merge Sort Application: Merge sort typically involves recursively dividing
the list into halves, sorting each half, and then merging them back together.
This approach is missing the recursive division and sorting.

3. Node Management: Ensure that you correctly manage pointers (p, q, r) to
traverse and swap nodes as needed. Your current logic seems to attempt a swap
based on a condition (q->val < r->val), but it lacks the full merge sort
logic.*/

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode* sortList(ListNode* head) {
    // Base case: empty list or single element list
    if (head == nullptr || head->next == nullptr)
      return head;

    // Step 1: Divide the list into two halves
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* right = slow->next;
    slow->next = nullptr; // break the list into two parts

    // Step 2: Recursively sort each half
    ListNode* left_sorted = sortList(head);
    ListNode* right_sorted = sortList(right);

    // Step 3: Merge the sorted halves
    return merge(left_sorted, right_sorted);
  }

  // Merge two sorted lists
  ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }

    // Attach remaining nodes
    if (l1)
      tail->next = l1;
    if (l2)
      tail->next = l2;

    return dummy.next;
  }
};
// sub: https://leetcode.com/problems/sort-list/submissions/1534382702/

class Solution2 { // optimised
public:
  ListNode* sortList(ListNode* head) {
    // Base case: empty list or single node
    if (!head || !head->next)
      return head;

    // Step 1: Split the list into two halves
    ListNode* mid = getMiddle(head);
    ListNode* right = mid->next;
    mid->next = nullptr; // Break the list into two halves

    // Step 2: Recursively sort both halves
    ListNode* leftSorted = sortList(head);
    ListNode* rightSorted = sortList(right);

    // Step 3: Merge the sorted halves
    return merge(leftSorted, rightSorted);
  }

private:
  // Function to find the middle node of the linked list
  ListNode* getMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next; // Start fast one step ahead for better split

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  // Function to merge two sorted linked lists
  ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }

    // Attach remaining nodes
    tail->next = l1 ? l1 : l2;

    return dummy.next;
  }
};
// sub: https://leetcode.com/problems/sort-list/submissions/1534391537/
// sol:
// https://leetcode.com/problems/sort-list/solutions/6387909/148-sort-list-by-nalindalal2004-v27u/
