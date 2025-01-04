/* https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
703. Kth Largest Element in a Stream

You are part of a university admissions office and need to keep track of the kth
highest test score from applicants in real-time. This helps to determine cut-off
marks for interviews and admissions dynamically as new applicants submit their
scores.

You are tasked to implement a class which, for a given integer k, maintains a
stream of test scores and continuously returns the kth highest test score after
a new score has been submitted. More specifically, we are looking for the kth
highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the
stream of test scores nums. int add(int val) Adds a new test score val to the
stream and returns the element representing the kth largest element in the pool
of test scores so far.


Example 1:

Input:
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

Output: [null, 4, 5, 5, 8, 8]

Explanation:

KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3); // return 4
kthLargest.add(5); // return 5
kthLargest.add(10); // return 5
kthLargest.add(9); // return 8
kthLargest.add(4); // return 8

Example 2:

Input:
["KthLargest", "add", "add", "add", "add"]
[[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]

Output: [null, 7, 7, 7, 8]

Explanation:

KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
kthLargest.add(2); // return 7
kthLargest.add(10); // return 7
kthLargest.add(9); // return 7
kthLargest.add(9); // return 8


Constraints:

0 <= nums.length <= 104
1 <= k <= nums.length + 1
-104 <= nums[i] <= 104
-104 <= val <= 104
At most 104 calls will be made to add.*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class KthLargest {
private:            // problem1, intialise vector and integer
  vector<int> nums; // Class member to store the stream of numbers
  int k;            // Class member to store k

public:
  KthLargest(int k, vector<int>& nums) {
    // kth highest test-score; dynamically update the cut-off marks
    // initializes the object with the integer k and the stream of test scores
    // nums.
    sort(this->nums.begin(), this->nums.end(), greater<int>());
    if (this->nums.size() > k) {
      this->nums.resize(k);
    }
  }

  int add(int val) {
    // maintain stream of test score
    // add a new entry to stream;
    // return kth highest score
    nums.push_back(val);
    sort(nums.begin(), nums.end(), greater<int>());

    // Keep only the top-k elements
    if (nums.size() > k) {
      nums.resize(k);
    }

    // Return the kth largest element
    return nums[k - 1];
  }
};
// tle - Sorting the nums vector every time a new element is added takes
// O(nlogn), where n is the size of the vector

// using a priority_queue to store top-k largest elements
class KthLargest1 {
private:
  priority_queue<int, vector<int>, greater<int>>
      minHeap; // Min-heap to store top-k largest elements  // Space- O(k)
  int k;       // The value of k

public:
  KthLargest(int k, vector<int>& nums) {
    this->k = k;

    // Insert all elements into the heap and maintain the heap size
    for (int num : nums) {
      add(num);
    }
  }

  int add(int val) { // O(logk)
    // Push the new value into the heap
    minHeap.push(val);

    // If the heap size exceeds k, remove the smallest element
    if (minHeap.size() > k) {
      minHeap.pop();
    }

    // The top element of the heap is the k-th largest element
    return minHeap.top();
  }
};
// Your KthLargest object will be instantiated and called as such:
// Time: O(n log k)
// Space: O(k)
int main() {
  int k = 3;                       // Example: Find the 3rd largest number
  vector<int> nums = {4, 5, 8, 2}; // Example input array

  // Create an instance of KthLargest
  KthLargest* obj = new KthLargest(k, nums);

  // Example: Add new values to the stream and print the k-th largest number
  cout << obj->add(3) << endl;  // Output: 4
  cout << obj->add(5) << endl;  // Output: 5
  cout << obj->add(10) << endl; // Output: 5
  cout << obj->add(9) << endl;  // Output: 8
  cout << obj->add(4) << endl;  // Output: 8

  delete obj; // Clean up dynamically allocated memory
  return 0;
}

// submission:
// https://leetcode.com/problems/kth-largest-element-in-a-stream/submissions/1496908322/
