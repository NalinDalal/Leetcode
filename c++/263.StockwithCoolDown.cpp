/* 309. Best Time to Buy and Sell Stock with Cooldown

You are given an array prices where prices[i] is the price of a given stock on
the ith day.

Find the maximum profit you can achieve. You may complete as many transactions
as you like (i.e., buy one and sell one share of the stock multiple times) with
the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown
one day). Note: You may not engage in multiple transactions simultaneously
(i.e., you must sell the stock before you buy again).



Example 1:
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:
Input: prices = [1]
Output: 0


Constraints:
1 <= prices.length <= 5000
0 <= prices[i] <= 1000 */

// intuition
// price on ith day
// if sell on ith day, can't buy on i+1th day
// also need to count profit
// need to generate all the choices in order to compare the profit.
// to try out all the possible choices, we will use recursion.
//

/*
The key is 3 states and 5 edges for state transition. 3 states arenotHold
(stock),hold (stock), andnotHold_cooldown. The initial values of the latter two
are negative infinity since they are meaningless, i.e. you won't hold stocks at
first and there's no cooldown at first. The 5 edges:

hold-----do nothing----->hold

hold-----sell----->notHold_cooldown

notHold-----do nothing ----->notHold

notHold-----buy----->hold

notHold_cooldown-----do nothing----->notHold*/
#include <algorithm>
#include <vector>
using std::vector, std::max;
class Solution {
public:
  int getAns(vector<int>& prices, int ind, int buy, vector<vector<int>>& dp) {
    int n = prices.size();
    if (ind >= n)
      return 0;

    if (dp[ind][buy] != -1)
      return dp[ind][buy];

    int profit;

    if (buy == 0) { // We can buy the stock
      profit = max(0 + getAns(prices, ind + 1, 0, dp),
                   -prices[ind] + getAns(prices, ind + 1, 1, dp));
    }

    if (buy == 1) { // We can sell the stock
      profit = max(0 + getAns(prices, ind + 1, 1, dp),
                   prices[ind] + getAns(prices, ind + 2, 0, dp));
    }
    return dp[ind][buy] = profit;
  }

  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));

    return getAns(prices, 0, 0, dp);
  }
};
// sub:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/1552557189/
// sol:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solutions/6458072/309-best-time-to-buy-and-sell-stock-with-1tlz/
