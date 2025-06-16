//2016. Maximum Difference Between Increasing Elements
function maximumDifference(nums: number[]): number {
  let maxAns: number = -1;
  for (let i = 0; i < nums.length; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      if (nums[i] < nums[j]) maxAns = Math.max(maxAns, nums[j] - nums[i]);
    }
  }
  return maxAns;
}
//sub:
//https://leetcode.com/problems/maximum-difference-between-increasing-elements/submissions/1665434131/?envType=daily-question&envId=2025-06-16
//sol: https://leetcode.com/problems/maximum-difference-between-increasing-elements/solutions/6848067/2016-maximum-difference-between-increasi-ls3w/
