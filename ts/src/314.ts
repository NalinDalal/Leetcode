//3202. Find the Maximum Length of Valid Subsequence II
function maximumLength(nums: number[], k: number): number {
  let ans = 0;
  const n = nums.length;

  for (let val = 0; val < k; val++) {
    const dp = Array(k).fill(0);

    for (const x of nums) {
      const mod = x % k;
      const requiredPrevMod = (val - mod + k) % k;
      dp[mod] = Math.max(dp[mod], dp[requiredPrevMod] + 1);
      ans = Math.max(ans, dp[mod]);
    }
  }

  return ans;
}

//sub: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/submissions/1700909584/?envType=daily-question&envId=2025-07-17
//sol: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/solutions/6969313/3202-find-the-maximum-length-of-valid-su-kfj0/
