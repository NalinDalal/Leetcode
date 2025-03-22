//188. Best Time to Buy and Sell Stock IV
impl Solution {
    pub fn max_profit(k: i32, prices: Vec<i32>) -> i32 {
        let n = prices.len();
    if n == 0 || k == 0 {
        return 0;
    }

    // If k is large enough, treat as unlimited transactions
    if k as usize >= n / 2 {
        let mut profit = 0;
        for i in 1..n {
            if prices[i] > prices[i - 1] {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }

    let mut dp = vec![vec![0; n]; (k + 1) as usize];

    for i in 1..=k as usize {
        let mut max_prev = -prices[0]; // max(dp[i-1][m] - prices[m])
        for j in 1..n {
            dp[i][j] = dp[i][j - 1].max(prices[j] + max_prev);
            max_prev = max_prev.max(dp[i - 1][j] - prices[j]);
        }
    }

    dp[k as usize][n - 1]
    }
}
//sub: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/1581844571/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/solutions/6564832/188-best-time-to-buy-and-sell-stock-iv-b-zxst/
