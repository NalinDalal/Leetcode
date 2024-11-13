/* 2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a
single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading
zeros.*/

// Intuition
/* The two linked lists represent numbers, where each node contains a single
digit, and the digits are stored in reverse order (i.e., the 1's place is at the
head of the list). The task is to add these two numbers digit by digit and
handle any carry that results from summing two digits. The challenge is to keep
track of the carry and move through both linked lists simultaneously.*/

// Approach:
/*Initialization:

Start from the head (least significant digit) of both linked lists.
Initialize a carry variable to 0 to store any overflow during addition.
Create a dummy node to simplify result list creation.
Iterating through the Lists:

Traverse both linked lists from left to right (which corresponds to adding
digits from the least significant digit to the most significant digit). For each
pair of corresponding nodes, add their values along with the carry. The new
digit is the sum modulo 10, and the carry is the integer division of the sum
by 10. Handle Remaining Digits:

If one linked list is longer than the other, continue the addition process with
the remaining digits of the longer list, still considering the carry. Final
Carry:

After processing both lists, if there's still a carry left, append it to the
result list. Edge Cases:

If both linked lists are empty or represent zero, the result should be zero.
Ensure that the resulting list is correctly terminated.*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *dummyHead = new ListNode(0); // Dummy node to start the result list
  ListNode *current = dummyHead;
  int carry = 0;

  // Traverse both lists
  while (l1 != nullptr || l2 != nullptr || carry != 0) {
    // Get the values from l1 and l2, or 0 if we've reached the end of either
    // list
    int x = (l1 != nullptr) ? l1->val : 0;
    int y = (l2 != nullptr) ? l2->val : 0;

    // Calculate the sum of the current digits and the carry
    int sum = x + y + carry;

    // Update carry for next iteration
    carry = sum / 10;

    // Create a new node for the current digit (sum mod 10)
    current->next = new ListNode(sum % 10);
    current = current->next;

    // Move to the next nodes in l1 and l2, if available
    if (l1 != nullptr)
      l1 = l1->next;
    if (l2 != nullptr)
      l2 = l2->next;
  }

  // The dummy node's next pointer points to the actual result list
  return dummyHead->next;
}

// Helper function to print the linked list
void printList(ListNode *node) {
  while (node != nullptr) {
    cout << node->val << " ";
    node = node->next;
  }
  cout << endl;
}

// Helper function to create a linked list from an array
ListNode *createList(int arr[], int size) {
  ListNode *head = new ListNode(arr[0]);
  ListNode *current = head;
  for (int i = 1; i < size; ++i) {
    current->next = new ListNode(arr[i]);
    current = current->next;
  }
  return head;
}

int main() {
  // Test example
  int arr1[] = {2, 4, 3}; // Represents the number 342
  int arr2[] = {5, 6, 4}; // Represents the number 465

  ListNode *l1 = createList(arr1, 3);
  ListNode *l2 = createList(arr2, 3);

  ListNode *result = addTwoNumbers(l1, l2);

  cout << "Sum: ";
  printList(result); // Output should be: 7 0 8 (Represents 807)

  return 0;
}

/* Complexity:
Time Complexity: O(max(m, n)), where m and n are the lengths of the two linked
lists, since we traverse both lists once. Space Complexity: O(max(m, n)) for
storing the result in a new linked list.*/
