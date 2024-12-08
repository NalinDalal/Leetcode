/*
234. Palindrome Linked List

Given the head of a singly linked list, return true if it is a palindrome or
false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false


Constraints:
The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
*/

// Logic/Approach:
/*
 1st edge case: check is list is empty -> return true in that case

 now initialise a vector(array) and log the node values in that vector

 once done, use 2 pointers to compare- left, right
 function{
 while(left<right){
if (values[left] != values[right]) {
                return false; // If any element mismatch, it's not a palindrome
            }
            left++;
            right--;
        }
 }
 return true;}
*/

// Code:
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  bool isPalindrome(ListNode* head) {
    // check if list is empty ot single element only
    if (!head || head->next) {
      return true;
    }

    // initialise a vector
    std::vector<int> values;
    ListNode* current = head;

    // Traverse the linked list and store node values in a vector
    while (current) {
      values.push_back(current->val);
      current = current->next;
    }

    // Use two pointers to compare elements from both ends of the vector
    int left = 0;
    int right = values.size() - 1;
    while (left < right) {
      if (values[left] != values[right]) {
        return false; // If any element mismatch, it's not a palindrome
      }
      left++;
      right--;
    }

    return true; // All elements match, it's a palindrome
  }
};
