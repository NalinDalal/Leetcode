//312. Burst Balloons
function maxCoins(nums: number[]): number {
  let n = nums.length;
  nums.unshift(1);
  //nums.prepend(nums.begin(),1);
  nums.push(1);

  const dp: number[][] = Array(n + 2)
    .fill(null)
    .map(() => Array(n + 2).fill(0));

  for (let len = 1; len <= n; len++) {
    for (let left = 1; left <= n - len + 1; left++) {
      let right = left + len - 1;

      for (let i = left; i <= right; i++) {
        let coins = nums[left - 1] * nums[i] * nums[right + 1];
        coins += dp[left][i - 1];
        coins += dp[i + 1][right];

        dp[left][right] = Math.max(dp[left][right], coins);
      }
    }
  }
  return dp[1][n];
}
//sub:https://leetcode.com/problems/burst-balloons/submissions/1560037479/
//sol: https://leetcode.com/problems/burst-balloons/solutions/6484518/312-burst-balloons-by-nalindalal2004-pzg1/
