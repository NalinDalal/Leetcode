/* 918. Maximum Sum Circular Subarray
Given a circular integer array nums of length n, return the maximum possible sum
of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the
array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the
previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once.
Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not
exist i <= k1, k2 <= j with k1 % n == k2 % n.



Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.


Constraints:

n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
*/

// return the maximum sum of a non-empty subarray, where the subarray can wrap
// around the end of the array.

/* Key Ideas:
You solve it using a combination of:

Kadane’s Algorithm for the maximum subarray sum (non-circular).

To find the circular subarray sum, subtract the minimum subarray sum from the
total array sum.

Edge Case:
If all elements are negative, then the circular sum approach will incorrectly
return 0 (which is not a valid subarray), so you just return the result from
Kadane’s.*/

class Solution {
public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int total = 0, maxSum = nums[0], curMax = 0;
    int minSum = nums[0], curMin = 0;

    for (int num : nums) {
      curMax = max(num, curMax + num);
      maxSum = max(maxSum, curMax);

      curMin = min(num, curMin + num);
      minSum = min(minSum, curMin);

      total += num;
    }

    // If all numbers are negative, return the maximum one (non-circular)
    if (maxSum < 0)
      return maxSum;

    // Otherwise, maximum of normal max subarray and circular case
    return max(maxSum, total - minSum);
  }
};
// Time: O(n)
// Space: O(1)
//  sub:
//  https://leetcode.com/problems/maximum-sum-circular-subarray/submissions/1599073808/?envType=study-plan-v2&envId=top-interview-150
//  sol:
//  https://leetcode.com/problems/maximum-sum-circular-subarray/solutions/6623843/918-maximum-sum-circular-subarray-by-nal-009f/
