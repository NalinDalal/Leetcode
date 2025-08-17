//837. New 21 Game
impl Solution {
    pub fn new21_game(n: i32, k: i32, max_pts: i32) -> f64 {
        let n = n as usize;
        let k = k as usize;
        let max_pts = max_pts as usize;

        let mut dp = vec![0.0; n + 1];
        dp[0] = 1.0;
        let mut s = if k > 0 { 1.0 } else { 0.0 };

        for i in 1..=n {
            dp[i] = s / max_pts as f64;
            if i < k {
                s += dp[i];
            }
            if i >= max_pts && i - max_pts < k {
                s -= dp[i - max_pts];
            }
        }

        dp[k..=n].iter().sum()
    }
}
//sub: https://leetcode.com/problems/new-21-game/submissions/1737998390/?envType=daily-question&envId=2025-08-17
//sol: https://leetcode.com/problems/new-21-game/solutions/7090702/837-new-21-game-by-nalindalal2004-wt5i/
