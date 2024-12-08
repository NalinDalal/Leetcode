/* 86. Partition List

Given the head of a linked list and a value x, partition it such that all nodes
less than x come before nodes greater than or equal to x. You should preserve
the original relative order of the nodes in each of the two partitions.

Example 1:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:
Input: head = [2,1], x = 2
Output: [1,2]


Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  // basically sort the ll given a node x, x se jitne bhi chote nodes h usse
  // phele aane chahoye, baaki se farak nhi padta
  // after node x sort the ll such that, the sorted is for whole ll
  // preserve original relative order of ll
  ListNode* partition(ListNode* head, int x) {
    // Dummy nodes for the two lists
    ListNode* lessHead = new ListNode(0);    // For values < x
    ListNode* greaterHead = new ListNode(0); // For values >= x
    ListNode* less = lessHead;
    ListNode* greater = greaterHead;

    while (head != nullptr) {
      if (head->val < x) {
        less->next = head; // Append to 'less' list
        less = less->next;
      } else {
        greater->next = head; // Append to 'greater' list
        greater = greater->next;
      }
      head = head->next; // Move to the next node
    }

    // Terminate the 'greater' list
    greater->next = nullptr;

    // Connect 'less' list with 'greater' list
    less->next = greaterHead->next;

    // Save the head of the new list
    ListNode* newHead = lessHead->next;

    // Clean up dummy nodes
    delete lessHead;
    delete greaterHead;

    return newHead;
  }
};

/* Separate the Nodes:
Use two lists: one for nodes with values < x and another for nodes with values
>= x.

    Traverse Once:
Iterate through the original list, appending nodes to the appropriate list.

    Connect the Two Lists:
Connect the last node of the < x list to the head of the >= x list.

    Handle Edge Cases:
Ensure the >= x list ends with nullptr to avoid cycles.

Time Complexity:
𝑂(𝑛), where 𝑛 is the number of nodes in the list (one pass).
Space Complexity: O(1) additional space (aside from dummy nodes).*/

int main() {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(4);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(2);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(2);
  cout << head->next->next->next->next->next->val << endl;

  Solution obj;
  ListNode* head1 = obj.partition(head, 3);
  cout << head1->next->next->next->next->next->val << endl;
  return 0;
}

// Time complexity:O(n)

// Space complexity:O(1)
