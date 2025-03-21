//123. Best Time to Buy and Sell Stock III
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        if prices.is_empty() {
            return 0;
        }

        let mut first_buy = i32::MIN;
        let mut first_sell = 0;
        let mut second_buy = i32::MIN;
        let mut second_sell = 0;

        for price in prices {
            first_buy = first_buy.max(-price); // First buy
            first_sell = first_sell.max(first_buy + price); // First sell
            second_buy = second_buy.max(first_sell - price); // Second buy
            second_sell = second_sell.max(second_buy + price); // Second sell
        }

        second_sell // Return max profit after two transactions
    }
}
//sub: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/1580869873/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/solutions/6561315/123-best-time-to-buy-and-sell-stock-iii-v5168/
