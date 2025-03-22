//188. Best Time to Buy and Sell Stock IV
function maxProfit(k: number, prices: number[]): number {
  const n = prices.length;
  if (n === 0 || k === 0) return 0;

  // If k is large enough, we can consider it as infinite transactions
  if (k >= Math.floor(n / 2)) {
    let profit = 0;
    for (let i = 1; i < n; i++) {
      if (prices[i] > prices[i - 1]) {
        profit += prices[i] - prices[i - 1];
      }
    }
    return profit;
  }

  // DP table
  const dp: number[][] = Array(k + 1)
    .fill(0)
    .map(() => Array(n).fill(0));

  for (let i = 1; i <= k; i++) {
    let maxPrev = -prices[0]; // max(dp[i-1][m] - prices[m])
    for (let j = 1; j < n; j++) {
      dp[i][j] = Math.max(dp[i][j - 1], prices[j] + maxPrev);
      maxPrev = Math.max(maxPrev, dp[i - 1][j] - prices[j]);
    }
  }

  return dp[k][n - 1];
}
//sub: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/1581844244/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/solutions/6564832/188-best-time-to-buy-and-sell-stock-iv-b-zxst/
