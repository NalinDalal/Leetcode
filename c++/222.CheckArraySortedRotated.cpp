/* https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2025-02-02

1752. Check if Array Is Sorted and Rotated
Easy
Topics
Companies
Hint
Given an array nums, return true if the array was originally sorted in
non-decreasing order, then rotated some number of positions (including zero).
Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length
such that A[i] == B[(i+x) % A.length], where % is the modulo operation.



Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value
3: [3,4,5,1,2]. Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.


Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

/*1. Iterate through the array and count how many times the current element is
greater than the next one.
2. Rotation Rule:
    - If the array is already sorted (no breaks), it's valid.
    - If there's exactly one break, it's valid only if the last element is less
than or equal to the first element (to account for rotation).
    - If there are more than one break, it can't be a rotated sorted array.
    */
class Solution {
public:
  bool check(vector<int>& nums) {
    int countBreaks = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      if (nums[i] > nums[(i + 1) % n]) {
        countBreaks++;
      }
    }

    return countBreaks <= 1;
  }
};

// sol:
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/solutions/6364065/1752-check-if-array-is-sorted-and-rotate-dn3t/
