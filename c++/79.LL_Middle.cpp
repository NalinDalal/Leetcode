/* 876. Middle of the Linked List

Given the head of a singly linked list, return the middle node of the linked
list. If there are two middle nodes, return the second middle node.


Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.


Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return
the second one.


Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100*/

#include <iostream>
using namespace std;

// intuition, approach: find the middle node, then find the next node of the
// middle node, return the next node
// for that we can use fast and slow pointers
// fast pointer moves twice as fast as slow pointers
// when the fast pointer reaches end of list, it will point to null, so return
// slow pointer

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* middleNode(ListNode* head) {
    if (!head)
      return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }
};

// implementation->
//  Helper functions to create and display a linked list
ListNode* createList(const vector<int>& vals) {
  if (vals.empty())
    return nullptr;
  ListNode* head = new ListNode(vals[0]);
  ListNode* current = head;
  for (size_t i = 1; i < vals.size(); ++i) {
    current->next = new ListNode(vals[i]);
    current = current->next;
  }
  return head;
}

void printList(ListNode* head) {
  while (head) {
    cout << head->val;
    if (head->next)
      cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

// Test cases
int main() {
  Solution solution;

  // Test case 1
  vector<int> vals1 = {1, 2, 3, 4, 5, 6};
  ListNode* head1 = createList(vals1);
  ListNode* result1 = solution.middleNode(head1);
  cout << "Output for [1, 2, 3, 4, 5, 6]: ";
  printList(result1);

  // Test case 2
  vector<int> vals2 = {1, 2, 3, 4, 5};
  ListNode* head2 = createList(vals2);
  ListNode* result2 = solution.middleNode(head2);
  cout << "Output for [1, 2, 3, 4, 5]: ";
  printList(result2);

  return 0;
}

// Time complexity:O(n)

// Space complexity:O(1)
