/* 287. Find the Duplicate Number

Given an array of integers nums containing n + 1 integers where each integer is
in the range [1, n] inclusive. There is only one repeated number in nums, return
this repeated number. You must solve the problem without modifying the array
nums and using only constant extra space.


Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3

Example 3:
Input: nums = [3,3,3,3,3]
Output: 3


Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which
appears two or more times.


Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?*/

/* //ahh, well what if sort the array
        //then just compare i with i+1
        //if true return the element
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==nums[i+1]){
                //return nums[i];
                break;
            }
        }
        return nums[i];
        */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int prevValue = nums[0];
    for (int index = 1; index < nums.size(); ++index) {
      int thisValue = nums[index];
      if (thisValue == prevValue) {
        //... Print it
        return thisValue;
      }
      prevValue = thisValue;
    }
    return -1;
  }
};

// The function now returns -1 after the loop if no duplicate is found (just as
// a safeguard, but the problem guarantees a duplicate). The key fix is ensuring
// there's a return statement at the end of the function.

// Time Complexity : O(nlogn)
// Space Complexity : O(1)

// Can you solve the problem in linear runtime complexity?

/*Key Insight:
Treat the array as a linked list where:
The value at nums[i] is the "next node" (i.e., follow nums[i] to jump to
the next index). The problem guarantees that there is at least one
duplicate, meaning that there must be a cycle in this "linked list."
*/

/* Algorithm Steps:
Phase 1: Finding the Intersection Point
Use two pointers:
Tortoise moves one step at a time (tortoise = nums[tortoise]).
Hare moves two steps at a time (hare = nums[nums[hare]]).
The goal is to detect a cycle. Since there is a duplicate, the two
pointers will eventually meet inside the cycle.

Phase 2: Finding the Entrance to the Cycle (Duplicate Number)
Once a cycle is detected, reset one pointer to the start of the array, and
move both pointers one step at a time. The point where they meet is the
duplicate number.*/

class Solution2 {
public:
  int findDuplicate(vector<int> &nums) {
    // Phase 1: Finding the intersection point
    int tortoise = nums[0];
    int hare = nums[0];

    do {
      tortoise = nums[tortoise]; // Move tortoise one step
      hare = nums[nums[hare]];   // Move hare two steps
    } while (tortoise != hare); // Loop until they meet

    // Phase 2: Finding the entrance to the cycle (duplicate number)
    tortoise = nums[0]; // Reset tortoise to the start

    while (tortoise != hare) {
      tortoise = nums[tortoise]; // Move both one step at a time
      hare = nums[hare];
    }

    return hare; // The duplicate number
  }
};

/* Explanation:
Phase 1 (Cycle Detection): The two pointers, tortoise and hare, start at the
same point (nums[0]). hare moves twice as fast as tortoise. If there’s a
duplicate (which implies a cycle in the "linked list" structure), they will
eventually meet at some point inside the cycle.

Phase 2 (Finding the Duplicate):
After detecting the cycle, resetting one of the pointers (tortoise) to the start
of the array and moving both pointers at the same speed will make them meet at
the starting point of the cycle, which is the duplicate number.

Time and Space Complexity:

Time Complexity: O(n)
Both phases (detecting the cycle and finding the entrance) take linear time
because each pointer moves through the array at most twice.

Space Complexity: O(1)
The algorithm only uses a constant amount of extra space for the two pointers
(tortoise and hare).*/

int main() {
  // Test case 1
  vector<int> nums1 = {1, 3, 4, 2, 2};
  Solution sol1;
  cout << "Output for Solution 1 (Sorting): " << sol1.findDuplicate(nums1)
       << endl; // Expected output: 2

  // Test case 2
  vector<int> nums2 = {3, 1, 3, 4, 2};
  Solution sol2;
  cout << "Output for Solution 1 (Sorting): " << sol2.findDuplicate(nums2)
       << endl; // Expected output: 3

  // Test case 3
  vector<int> nums3 = {3, 3, 3, 3, 3};
  Solution sol3;
  cout << "Output for Solution 1 (Sorting): " << sol3.findDuplicate(nums3)
       << endl; // Expected output: 3

  // Test case 4 (Testing Solution2: Floyd's Tortoise and Hare algorithm)
  Solution2 sol4;
  cout << "Output for Solution 2 (Cycle Detection): "
       << sol4.findDuplicate(nums1) << endl; // Expected output: 2
  cout << "Output for Solution 2 (Cycle Detection): "
       << sol4.findDuplicate(nums2) << endl; // Expected output: 3
  cout << "Output for Solution 2 (Cycle Detection): "
       << sol4.findDuplicate(nums3) << endl; // Expected output: 3

  return 0;
}
