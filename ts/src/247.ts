//1920. Build Array from Permutation

function buildArray(nums: number[]): number[] {
  const ans: number[] = new Array(nums.length);
  for (let i = 0; i < nums.length; i++) {
    ans[i] = nums[nums[i]];
  }
  return ans;
}
//sub: https://leetcode.com/problems/build-array-from-permutation/submissions/1626598047/?envType=daily-question&envId=2025-05-06
