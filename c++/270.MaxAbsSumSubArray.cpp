/*1749. Maximum Absolute Sum of Any Subarray

You are given an integer array nums. The absolute sum of a subarray [numsl,
numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.


Example 1:
Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.

Example 2:
Input: nums = [2,-5,1,-4,3,-2]
Output: 8
Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8)
= 8.


Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104

Hint 1: What if we asked for maximum sum, not absolute sum?
Hint 2: It's a standard problem that can be solved by Kadane's algorithm.
Hint 3: The key idea is the max absolute sum will be either the max sum or the
min sum. Hint 4: So just run kadane twice, once calculating the max sum and once
calculating the min sum.*/

class Solution {
public:
  int maxAbsoluteSum(vector<int>& nums) {
    // so find some elements
    // sum them then it's abs
    // return max abs sum
    // track both max and min subarray sum
    // ans=abs(maxSum-minSum)
    // maxSum=maximum running sum
    // minSum=minimum running sum
    int sum = 0, minSum = 0, maxSum = 0;
    for (int num : nums) {
      sum += num;
      if (sum > maxSum)
        maxSum = sum;
      if (sum < minSum)
        minSum = sum;
    }
    return abs(maxSum - minSum);
  }
};
// sub:https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/submissions/1556139310/?envType=daily-question&envId=2025-02-26
// sol:
// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/solutions/6470853/1749-maximum-absolute-sum-of-any-subarra-ld5t/
