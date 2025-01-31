/* 141. Linked List Cycle
Given head, the head of a linked list, determine if the linked list has a cycle
in it.

There is a cycle in a linked list if there is some node in the list that can be
reached again by continuously following the next pointer. Internally, pos is
used to denote the index of the node that tail's next pointer is connected to.
Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.


Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the
1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the
0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.


Constraints:

The number of the nodes in the list is in the range [0, 104].
-10^5 <= Node.val <= 10^5
pos is -1 or a valid index in the linked-list.

Follow up: Can you solve it using O(1) (i.e. constant) memory?*/

// Approach: Fast, Slow Pointer
// initialise a fast and a slow pointer, slow pointer moves 1 at a time,
// fast moves 2 at a time
// if fast gets behind slow in terms of places, then
// there must a cycle present but
// to Return true false-> log index of fast,slow at each iteration
// as soon as fast<slow -> return true else false

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode* head) {
    if (!head)
      return false;

    ListNode* slow = head;
    ListNode* fast = head;
    int step = 0; // For logging iterations

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;       // Slow moves 1 step
      fast = fast->next->next; // Fast moves 2 steps

      // Log the index (step) and values of slow and fast pointers
      // std::cout << "Step " << step << ": slow = " << slow->val << ", fast = "
      // << fast->val << std::endl;
      step++;

      // Cycle detected
      if (slow == fast) {
        // std::cout << "Cycle detected at step " << step << std::endl;
        return true;
      }
    }

    // No cycle found
    // std::cout << "No cycle found" << std::endl;
    return false;
  }
};
int main() {
  // Example of creating a linked list with a cycle
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = head->next; // Creating a cycle

  // Detect cycle
  Solution Solution;
  bool result = Solution.hasCycle(head);
  std::cout << "Cycle present: " << (result ? "Yes" : "No") << std::endl;

  return 0;
}
// Time complexity:O(n)
// Space complexity:O(1)
