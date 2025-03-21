//123. Best Time to Buy and Sell Stock III
function maxProfit(prices: number[]): number {
  if (prices.length === 0) return 0;

  let firstBuy = Number.MIN_SAFE_INTEGER,
    firstSell = 0;
  let secondBuy = Number.MIN_SAFE_INTEGER,
    secondSell = 0;

  for (const price of prices) {
    firstBuy = Math.max(firstBuy, -price); // First buy
    firstSell = Math.max(firstSell, firstBuy + price); // First sell
    secondBuy = Math.max(secondBuy, firstSell - price); // Second buy
    secondSell = Math.max(secondSell, secondBuy + price); // Second sell
  }

  return secondSell; // Max profit after two transactions
}
//sub: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/1580868629/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/solutions/6561315/123-best-time-to-buy-and-sell-stock-iii-v5168/
