/*123. Best Time to Buy and Sell Stock III

You are given an array prices where prices[i] is the price of a given stock on
the ith day. Find the maximum profit you can achieve. You may complete at most
two transactions. Note: You may not engage in multiple transactions
simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit =
3-0 = 3. Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit =
4-1 = 3.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit =
5-1 = 4. Note that you cannot buy on day 1, buy on day 2 and sell them later, as
you are engaging multiple transactions at the same time. You must sell before
buying again.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.


Constraints:
1 <= prices.length <= 105
0 <= prices[i] <= 105
*/

// Approach:
/* buy on minimum day
then sell after buying on maximum day
note: selling is allowed only after buying
find the best two opportunities to buy and sell the stock to maximize your
profit

Note: only 2 transaction then 4 variable: `firstBuy`, `firstSell`, `secondBuy`,
`secondSell`
- `firstBuy = max(firstBuy, -prices[i])` → Buy at a lower price.
- `firstSell = max(firstSell, firstBuy + prices[i])` → Sell at a higher price.
- `secondBuy = max(secondBuy, firstSell - prices[i])` → Use profit from the
first sell to buy again.
- `secondSell = max(secondSell, secondBuy + prices[i])` → Sell for the second
time at a higher price.
    */
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty())
      return 0;

    int firstBuy = INT_MIN, firstSell = 0;
    int secondBuy = INT_MIN, secondSell = 0;

    for (int price : prices) {
      firstBuy = max(firstBuy, -price);                // First buy
      firstSell = max(firstSell, firstBuy + price);    // First sell
      secondBuy = max(secondBuy, firstSell - price);   // Second buy
      secondSell = max(secondSell, secondBuy + price); // Second sell
    }

    return secondSell; // Max profit after two transactions
  }
};
// Time: O(n)
// Space: O(1)
// sub:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/1580861863/?envType=study-plan-v2&envId=top-interview-150
// sol:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/solutions/6561315/123-best-time-to-buy-and-sell-stock-iii-v5168/
