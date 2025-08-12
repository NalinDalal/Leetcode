//2787. Ways to Express an Integer as Sum of Powers
impl Solution {
    pub fn number_of_ways(n: i32, x: i32) -> i32 {
        const MOD: i64 = 1_000_000_007;

        // Convert to usize/u32 for calculations and indexing
        let n_usize = n as usize;
        let x_u32 = x as u32;

        // Find max base integer m such that m^x <= n
        let mut max_base = 1usize;
        while (max_base as i64).pow(x_u32) <= n as i64 {
            max_base += 1;
        }
        max_base -= 1;

        // Precompute powers
        let powers: Vec<i64> = (0..=max_base)
            .map(|i| (i as i64).pow(x_u32))
            .collect();

        // dp[k][j]: number of ways to write k as sum of unique powers up to j-th power
        let mut dp = vec![vec![0i64; max_base + 1]; n_usize + 1];

        // base case: ways to write 0 = 1 (use no numbers)
        for j in 0..=max_base {
            dp[0][j] = 1;
        }

        for k in 1..=n_usize {
            for j in 1..=max_base {
                dp[k][j] = dp[k][j - 1];
                let prev = k as i64 - powers[j];
                if prev >= 0 {
                    dp[k][j] = (dp[k][j] + dp[prev as usize][j - 1]) % MOD;
                }
            }
        }

        dp[n_usize][max_base] as i32
    }
}

//sub: https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/submissions/1731899656/?envType=daily-question&envId=2025-08-12
//sol: https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/solutions/7069842/2787-ways-to-express-an-integer-as-sum-o-900l/
