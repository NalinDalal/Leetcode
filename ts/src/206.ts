//368. Largest Divisible Subset
function largestDivisibleSubset(nums: number[]): number[] {
  if (nums.length === 0) return [];

  nums.sort((a, b) => a - b);
  const n = nums.length;
  const dp = new Array(n).fill(1);
  const prev = new Array(n).fill(-1);
  let maxIdx = 0;

  for (let i = 1; i < n; ++i) {
    for (let j = 0; j < i; ++j) {
      if (nums[i] % nums[j] === 0 && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        prev[i] = j;
      }
    }
    if (dp[i] > dp[maxIdx]) {
      maxIdx = i;
    }
  }

  const result: number[] = [];
  for (let i = maxIdx; i >= 0; i = prev[i]) {
    result.push(nums[i]);
    if (prev[i] === -1) break;
  }

  return result.reverse();
}
//sub: https://leetcode.com/problems/largest-divisible-subset/submissions/1598125026/?envType=daily-question&envId=2025-04-06
//sol: https://leetcode.com/problems/largest-divisible-subset/solutions/6620526/368-largest-divisible-subset-by-nalindal-m15d/
