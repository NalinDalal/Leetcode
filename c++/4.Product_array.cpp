/*
 * 238. Product of Array Except Self
Medium
Topics
Companies
Hint
Given an integer array nums, return an array answer such that answer[i] is equal
to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
integer.

You must write an algorithm that runs in O(n) time and without using the
division operation.



Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]


Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
integer.
*/
class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    // initialise prefix and suffix array
    // compute their own products
    // product of prefix,suffix
    int n = nums.size();
    int l = 1, r = 1;
    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++) {
      left[i] = l;
      if (i != n - 1)
        l = l * nums[i];
    }
    for (int i = n - 1; i >= 0; i--) {
      right[i] = r;
      if (i != 0) {
        r = r * nums[i];
      }
    }
    for (int i = 0; i < n; i++) {
      nums[i] = left[i] * right[i];
    }
    return nums;
  }
};
