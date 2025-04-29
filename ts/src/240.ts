//2962. Count Subarrays Where Max Element Appears at Least K Times
function countSubarrays(nums: number[], k: number): number {
  const maxElement = Math.max(...nums);
  let ans = 0;
  let start = 0;
  let maxElementsInWindow = 0;

  for (let end = 0; end < nums.length; end++) {
    if (nums[end] === maxElement) {
      maxElementsInWindow++;
    }
    while (maxElementsInWindow === k) {
      if (nums[start] === maxElement) {
        maxElementsInWindow--;
      }
      start++;
    }
    ans += start;
  }
  return ans;
}
//sub: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/submissions/1620703943/?envType=daily-question&envId=2025-04-29
