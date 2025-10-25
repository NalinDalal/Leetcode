//1716. Calculate Money in Leetcode Bankimpl Solution {
    pub fn total_money(n: i32) -> i32 {
        let weeks = n / 7;
    let rem = n % 7;

    let mut total = 7 * (weeks * (weeks + 1) / 2) + 21 * weeks;
    total += rem * (weeks + 1) + rem * (rem - 1) / 2;

    total
    }
}
//sub: https://leetcode.com/problems/calculate-money-in-leetcode-bank/submissions/1811538486/?envType=daily-question&envId=2025-10-25
//sol: https://leetcode.com/problems/calculate-money-in-leetcode-bank/solutions/7300975/1716-calculate-money-in-leetcode-bank-by-ipit/
