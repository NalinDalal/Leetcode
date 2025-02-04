/* https://leetcode.com/problems/maximum-ascending-subarray-sum/description/?envType=daily-question&envId=2025-02-04

1800. Maximum Ascending Subarray Sum
Given an array of positive integers nums, return the maximum possible sum of an
ascending subarray in nums.

A subarray is defined as a contiguous sequence of numbers in an array.

A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where
l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending.


Example 1:
Input: nums = [10,20,30,5,10,50]
Output: 65
Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.

Example 2:
Input: nums = [10,20,30,40,50]
Output: 150
Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of
150.

Example 3:
Input: nums = [12,17,15,13,10,11,12]
Output: 33
Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.


Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

class Solution {
public:
  int maxAscendingSum(vector<int>& nums) {
    // select a ascending subarray
    // find their max sum
    // iterate through the array once, extending the current subarray sum when
    // each number is greater than its predecessor and resetting it otherwise
    int curr = nums[0], ans = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      curr = nums[i] > nums[i - 1] ? curr + nums[i] : nums[i];
      ans = max(ans, curr);
    }
    return ans;
  }
};

// Time: O(n)
// Space:O(1)
// sub:
// https://leetcode.com/problems/maximum-ascending-subarray-sum/submissions/1531298437/?envType=daily-question&envId=2025-02-04
// sol:
// https://leetcode.com/problems/maximum-ascending-subarray-sum/solutions/6375073/1800-maximum-ascending-subarray-sum100-b-5289/
