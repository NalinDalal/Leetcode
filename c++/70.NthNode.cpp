/* 19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list
and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz


Follow up: Could you do this in one pass?
*/
// Logic:
/*
void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;

    delete todelete;    //necessary otherwise memory will be leaked
}

void deletion(node* &head,int val){

    if(head==NULL){
        return;
    }
    if(head->next==NULL){   //only one element
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;
}*/

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

//void deletion(node* &head,int val){

    if(head==NULL){
        return;
    }
    if(head->next==NULL){   //only one element
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;
    }
};*/

// issues:
/*The function should return the head of the list, but your current
implementation doesn't handle that properly. There's a function deleteAtHead()
mentioned, but it's not defined or used correctly. The while loop is incorrect
because it assumes you are looking for a node with a specific value, whereas
you're supposed to remove the nth node from the end. The function doesn't handle
edge cases well, such as when n equals the length of the list (i.e., you need to
remove the first node).*/

#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

// Function to print the linked list
void printList(ListNode *head) {
  while (head) {
    cout << head->val;
    if (head->next)
      cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

// Helper function to create a linked list from an array
ListNode *createList(const vector<int> &vals) {
  if (vals.empty())
    return nullptr;
  ListNode *head = new ListNode(vals[0]);
  ListNode *current = head;
  for (int i = 1; i < vals.size(); ++i) {
    current->next = new ListNode(vals[i]);
    current = current->next;
  }
  return head;
}

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // Create a dummy node to simplify edge cases (like removing the first node)
    ListNode *dummy = new ListNode(0, head);
    ListNode *slow = dummy;
    ListNode *fast = dummy;

    // Move the fast pointer `n + 1` steps ahead to create a gap of `n` between
    // fast and slow
    for (int i = 0; i <= n; ++i) {
      fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }

    // Now, slow points to the node before the one we need to remove
    ListNode *toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    // Return the new head (which might have changed if we deleted the first
    // node)
    ListNode *newHead = dummy->next;
    delete dummy; // Clean up the dummy node
    return newHead;
  }
};

/* Explanation:
Dummy Node: A dummy node is used to handle cases where the first node is
removed, simplifying edge cases. Two-pointer technique: The fast pointer is
moved n + 1 steps ahead so that when fast reaches the end of the list, slow is
at the node before the one to be deleted. Deletion: Once the correct node is
identified, it is removed, and we update the next pointer of the previous node.

This approach has a time complexity of 𝑂(𝐿), where 𝐿 is the length of the linked
list, and a space complexity of O(1).*/

int main() {
  Solution solution;

  // Test case 1
  ListNode *list1 = createList({1, 2, 3, 4, 5});
  cout << "Original list: ";
  printList(list1);
  ListNode *result1 = solution.removeNthFromEnd(list1, 2);
  cout << "After removing 2nd from end: ";
  printList(result1);
  cout << endl;

  // Test case 2
  ListNode *list2 = createList({1});
  cout << "Original list: ";
  printList(list2);
  ListNode *result2 = solution.removeNthFromEnd(list2, 1);
  cout << "After removing 1st from end: ";
  printList(result2);
  cout << endl;

  // Test case 3
  ListNode *list3 = createList({1, 2});
  cout << "Original list: ";
  printList(list3);
  ListNode *result3 = solution.removeNthFromEnd(list3, 1);
  cout << "After removing 1st from end: ";
  printList(result3);
  cout << endl;

  return 0;
}
