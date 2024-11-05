/* 206. Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the
reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []


Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000*/
#include <iostream>
using namespace std;
// Definition for singly-linked list.

struct ListNode {
  int val;                              // node intialised
  ListNode *next;                       // pointer initialised
  ListNode() : val(0), next(nullptr) {} // empty node inialised
  ListNode(int x)
      : val(x), next(nullptr) {
  } // last node i.e. where ll ends(node with nullptr)
  ListNode(int x, ListNode *next)
      : val(x), next(next) {} // normal node i.e. node in b/w(node with ptr)
};

// reverse ll->
// The idea is to use three pointers curr, prev, and forward to keep track of
// nodes to update reverse links. set prev_ptr as null set curr_ptr as head of
// ll run till curr!=NULL-> Listnode* forward=curr->next;-> set a pointer which
// runs along the original ll assign curr->next=prev    ->set a prev_ptr as next
// of new ll prev=curr;    -> set prev as curr curr=forward  -> set forward as
// curr to move forward
//
//
// return prev

class Solution {
public:
  ListNode *reverseList(ListNode *head) {

    ListNode *prev = NULL;
    ListNode *curr = head;

    while (curr != NULL) {
      ListNode *forward = curr->next;
      curr->next = prev;
      prev = curr;
      curr = forward;
    }
    return prev;
  }
};

int main() {
  // Constructing the linked list: 5 -> 3 -> 6 -> 4
  ListNode *head = new ListNode(5);
  head->next = new ListNode(3);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(4);

  Solution sol;
  ListNode *reversedList = sol.reverseList(head);

  // Print the reversed linked list
  while (reversedList != nullptr) {
    cout << reversedList->val << " ";
    reversedList = reversedList->next;
  }
  cout << endl;

  return 0;
}
