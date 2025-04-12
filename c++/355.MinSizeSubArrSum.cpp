/* 209. Minimum Size Subarray Sum
Given an array of positive integers nums and a positive integer target, return
the minimal length of a subarray whose sum is greater than or equal to target.
If there is no such subarray, return 0 instead.



Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem
constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0


Constraints:
1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104

*/

/* minimal length of subarray whose sum>=target
        subarray- contiguous non-empty sequence of elements
        int ans=0;

        find all subarrays
        check whose sum>=target
        return it's length

        return ans;
*/

class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int minLen = INT_MAX;
    int left = 0, sum = 0;

    for (int right = 0; right < n; ++right) {
      sum += nums[right];

      while (sum >= target) {
        minLen = min(minLen, right - left + 1);
        sum -= nums[left++];
      }
    }

    return minLen == INT_MAX ? 0 : minLen;
  }
};
// sub:
// https://leetcode.com/problems/minimum-size-subarray-sum/submissions/1604125807/?envType=study-plan-v2&envId=top-interview-150
// sol:
// https://leetcode.com/problems/minimum-size-subarray-sum/solutions/6641473/209-minimum-size-subarray-sum-by-nalinda-nf30/
