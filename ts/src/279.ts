//3423. Maximum Difference Between Adjacent Elements in a Circular Array
function maxAdjacentDistance(nums: number[]): number {
  let ans: number = Math.abs(nums[0] - nums[nums.length - 1]);
  for (let i = 0; i < nums.length - 1; i++) {
    ans = Math.max(ans, Math.abs(nums[i] - nums[i + 1]));
  }
  return ans;
}
//sub: https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/submissions/1661511246/?envType=daily-question&envId=2025-06-12
//sol: https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/solutions/6834794/3423-maximum-difference-between-adjacent-tvke/
