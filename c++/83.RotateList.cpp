/* 61. Rotate List

Given the head of a linked list, rotate the list to the right by k places.


Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]


Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 10^9
*/

#include <iostream>
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// length of ll-> divide the k by it
// upon division, we will get some remainder
// k%n
//
// Efficient Rotation: To rotate the list:

// Connect the tail to the head, making it circular.
// Break the circular connection at the appropriate point to form the rotated
// list.

class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0)
      return head;

    // Step 1: Compute the length of the list
    ListNode* current = head;
    int n = 1; // At least 1 node exists
    while (current->next) {
      current = current->next;
      n++;
    }

    // Step 2: Make the list circular
    current->next = head;

    // Step 3: Find the new head position
    k = k % n; // Effective rotations
    int stepsToNewHead = n - k;

    // Step 4: Break the circle at the new head
    ListNode* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
      newTail = newTail->next;
    }
    ListNode* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
  }
};

// Helper function to print the list
void printList(ListNode* head) {
  while (head) {
    std::cout << head->val << " ";
    head = head->next;
  }
  std::cout << std::endl;
}

// Main function for testing
int main() {
  // Create a sample list: [1, 2, 3, 4, 5]
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  Solution solution;
  int k = 2;
  ListNode* rotatedHead = solution.rotateRight(head, k);

  printList(rotatedHead); // Output: 4 5 1 2 3

  return 0;
}

/* Complexity Analysis
Time Complexity:

Computing the length of the list: O(n).
Locating the new head: O(n−k).
Total:O(n).
Space Complexity:
O(1), as we are using constant extra space.*/
