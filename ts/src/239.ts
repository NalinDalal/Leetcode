//2302. Count Subarrays With Score Less Than K
function countSubarrays(nums: number[], k: number): number {
  let ans: number = 0;
  let sum: number = 0;
  let left: number = 0;

  for (let right = 0; right < nums.length; right++) {
    sum += nums[right];

    // Shrink window if score >= k
    while (sum * (right - left + 1) >= k) {
      sum -= nums[left];
      left++;
    }

    // All subarrays ending at 'right' and starting from [left, right] are valid
    ans += right - left + 1;
  }
  return ans;
}
//sub: https://leetcode.com/problems/count-subarrays-with-score-less-than-k/submissions/1619878566/?envType=daily-question&envId=2025-04-28
