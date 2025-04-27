//3392. Count Subarrays of Length Three With a Condition

function countSubarrays(nums: number[]): number {
  let count = 0;
  let n = nums.length;

  for (let i = 0; i <= n - 3; ++i) {
    let first = nums[i];
    let second = nums[i + 1];
    let third = nums[i + 2];
    if (second % 2 == 0 && first + third == second / 2) {
      count++;
    }
  }

  return count;
}
//sub: https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/submissions/1619563956/?envType=daily-question&envId=2025-04-27
