//2327. Number of People Aware of a Secret
impl Solution {
    pub fn people_aware_of_secret(n: i32, delay: i32, forget: i32) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let n = n as usize;
        let delay = delay as usize;
        let forget = forget as usize;

        let mut dp = vec![0i64; n + 1];
        dp[1] = 1;

        let mut shareable: i64 = 0;
        let mut ans: i64 = 0;

        for day in 2..=n {
            if day >= delay + 1 {
                shareable = (shareable + dp[day - delay]) % MOD;
            }
            if day >= forget + 1 {
                shareable = (shareable - dp[day - forget] + MOD) % MOD;
            }
            dp[day] = shareable;
        }

        for day in n - forget + 1..=n {
            ans = (ans + dp[day]) % MOD;
        }

        ans as i32
    }
}
//sub: https://leetcode.com/problems/number-of-people-aware-of-a-secret/submissions/1764470869/?envType=daily-question&envId=2025-09-09
//sol: https://leetcode.com/problems/number-of-people-aware-of-a-secret/solutions/7170972/2327-number-of-people-aware-of-a-secret-z4gd6/
