//2348. Number of Zero-Filled Subarrays
function zeroFilledSubarray(nums: number[]): number {
  let count = 0;
  let streak = 0;

  for (const n of nums) {
    if (n === 0) {
      streak++;
      count += streak;
    } else {
      streak = 0;
    }
  }

  return count;
}
//sub: https://leetcode.com/problems/number-of-zero-filled-subarrays/submissions/1740252753/?envType=daily-question&envId=2025-08-19
//sol: https://leetcode.com/problems/number-of-zero-filled-subarrays/solutions/7097173/2348-number-of-zero-filled-subarrays-by-mk9bb/
