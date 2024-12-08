/*
* 704. Binary Search
* Given an array of integers nums which is sorted in ascending order, and an
integer target, write a function to search target in nums. If target exists,
then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
*/

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int s = 0;          // start point defined
    int e = size(nums); // end point defined
    if (e == 1) {
      return (nums[0] == target)
                 ? 0
                 : -1; // If only one element, return its index if it matches
                       // the target, otherwise return -1
    }
    while (s <= e) {
      int mid = (s + e) / 2; // mid element counter

      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        e = mid - 1;
      } else {
        s = mid + 1;
      }
    }
    return -1;
  }
};
