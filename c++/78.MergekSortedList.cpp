/* 23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in
ascending order. Merge all the linked-lists into one sorted linked-list and
return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 10^4.*/

// Intuition:
// what if we convert all ll into a array,merge them, sort them, again convert
// to ll?, cons very slow process.

// Approach
/* using Min-Heap:

Push the first node of each non-empty linked list into a min-heap (or priority
queue). Extract the node with the smallest value from the heap (this ensures
that we are always adding the smallest available node to the merged list). Push
the next node of the extracted node's list into the heap. Repeat until the heap
is empty, building the sorted merged list along the way.*/

// Comparator for the min-heap
struct compare {
  bool operator()(ListNode* a, ListNode* b) {
    return a->val > b->val; // min-heap based on node values
  }
};

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<int> values;

    // Step 1: Convert all linked lists to an array
    for (ListNode* list : lists) {
      while (list != nullptr) {
        values.push_back(list->val);
        list = list->next;
      }
    }

    // Step 2: Sort the array
    sort(values.begin(), values.end());

    // Step 3: Convert sorted array back to linked list
    ListNode* dummy = new ListNode(); // dummy node to simplify construction
    ListNode* current = dummy;
    for (int val : values) {
      current->next = new ListNode(val);
      current = current->next;
    }

    return dummy->next; // returning the actual merged list
  }
};

// Efficinet
// Push the first node of each non-empty linked list into a min-heap (or
// priority queue). Extract the node with the smallest value from the heap (this
// ensures that we are always adding the smallest available node to the merged
// list). Push the next node of the extracted node's list into the heap. Repeat
// until the heap is empty, building the sorted merged list along the way.

// TC- O(log k)
#include <queue>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// Comparator for the min-heap
struct compare {
  bool operator()(ListNode* a, ListNode* b) {
    return a->val > b->val; // min-heap based on node values
  }
};

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    // Min-heap to store the nodes
    priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

    // Step 1: Push the first node of each linked list into the heap
    for (ListNode* list : lists) {
      if (list) {
        minHeap.push(list);
      }
    }

    // Dummy node to act as the head of the merged list
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    // Step 2: Process the heap
    while (!minHeap.empty()) {
      // Get the smallest element (from the top of the heap)
      ListNode* smallest = minHeap.top();
      minHeap.pop();

      // Add the smallest element to the merged list
      current->next = smallest;
      current = current->next;

      // If there is a next node in the list of the extracted node, push it into
      // the heap
      if (smallest->next) {
        minHeap.push(smallest->next);
      }
    }

    // Return the head of the merged linked list
    return dummy->next;
  }
};
