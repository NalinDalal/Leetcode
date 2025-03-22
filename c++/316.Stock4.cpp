/*188. Best Time to Buy and Sell Stock IV

You are given an integer array prices where prices[i] is the price of a given
stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k
transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must
sell the stock before you buy again).

Example 1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit =
4-2 = 2.

Example 2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit =
6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit =
3-0 = 3.


Constraints:
1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000
*/

class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    // dp[i][j]-max profit using i transaction till j day
    // dp[i][j]=max(dp[i][j-1], prices[j] - prices[m] + dp[i-1][m])->m<j;check
    // if buying on m day is profitable k==0/empty return 0
    int n = prices.size();
    if (n == 0 || k == 0)
      return 0;

    // If k is large enough, treat as unlimited transactions
    if (k >= n / 2) {
      int profit = 0;
      for (int i = 1; i < n; ++i)
        if (prices[i] > prices[i - 1])
          profit += prices[i] - prices[i - 1];
      return profit;
    }

    vector<vector<int>> dp(k + 1, vector<int>(n, 0));

    for (int i = 1; i <= k; ++i) {
      int maxPrev = -prices[0]; // max(dp[i-1][m] - prices[m])
      for (int j = 1; j < n; ++j) {
        dp[i][j] = max(dp[i][j - 1], prices[j] + maxPrev);
        maxPrev = max(maxPrev, dp[i - 1][j] - prices[j]);
      }
    }

    return dp[k][n - 1];
  }
};
// sub:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/1581841167/?envType=study-plan-v2&envId=top-interview-150
// sol:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/solutions/6564832/188-best-time-to-buy-and-sell-stock-iv-b-zxst/
