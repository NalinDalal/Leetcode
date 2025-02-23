//309. Best Time to Buy and Sell Stock with Cooldown
function getAns(
  prices: number[],
  ind: number,
  buy: number,
  dp: number[][],
): number {
  const n = prices.length;
  if (ind >= n) return 0;

  if (dp[ind][buy] !== -1) return dp[ind][buy];

  let profit: number;

  if (buy === 0) {
    // We can buy the stock
    profit = Math.max(
      getAns(prices, ind + 1, 0, dp),
      -prices[ind] + getAns(prices, ind + 1, 1, dp),
    );
  } else {
    // We can sell the stock
    profit = Math.max(
      getAns(prices, ind + 1, 1, dp),
      prices[ind] + getAns(prices, ind + 2, 0, dp),
    );
  }

  return (dp[ind][buy] = profit);
}

function maxProfit(prices: number[]): number {
  const n = prices.length;
  const dp: number[][] = new Array(n)
    .fill(null)
    .map(() => new Array(2).fill(-1));

  return getAns(prices, 0, 0, dp);
}

// Example Usage:
console.log(maxProfit([1, 2, 3, 0, 2])); // Example test case

//sub: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/1552561637/
//sol: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solutions/6458072/309-best-time-to-buy-and-sell-stock-with-1tlz/
