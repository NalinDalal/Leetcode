//122. Best Time to Buy and Sell Stock II
function maxProfit(prices: number[]): number {
  let n: number = prices.length,
    maxProfit: number = 0;
  for (let i = 1; i < n; i++) {
    if (prices[i] > prices[i - 1]) maxProfit += prices[i] - prices[i - 1];
  }
  return maxProfit;
}

//sub: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/1579639887/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/solutions/6557463/122-best-time-to-buy-and-sell-stock-ii-b-uy7q/
