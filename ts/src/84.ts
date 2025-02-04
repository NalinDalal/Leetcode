//1800. Maximum Ascending Subarray Sum
function maxAscendingSum(nums: number[]): number {
  let curr: number = nums[0],
    ans: number = nums[0];
  for (let i = 1; i < nums.length; ++i) {
    curr = nums[i] > nums[i - 1] ? curr + nums[i] : nums[i];
    ans = Math.max(ans, curr);
  }
  return ans;
}

//sub: https://leetcode.com/problems/maximum-ascending-subarray-sum/submissions/1531302504/?envType=daily-question&envId=2025-02-04
//sol: https://leetcode.com/problems/maximum-ascending-subarray-sum/solutions/6375073/1800-maximum-ascending-subarray-sum100-b-5289/
