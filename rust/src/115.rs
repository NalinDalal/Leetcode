//115. Distinct Subsequences
impl Solution {
    pub fn num_distinct(s: String, t: String) -> i32 {
        let m = s.len();
        let n = t.len();
        let s = s.as_bytes();
        let t = t.as_bytes();

        // Use a 2D vector to store counts, initialized with 0
        let mut dp = vec![vec![0u64; n + 1]; m + 1];

        // Base case: An empty t is a subsequence of any s
        for i in 0..=m {
            dp[i][0] = 1;
        }

        // Fill DP table
        for i in 1..=m {
            for j in 1..=n {
                if s[i - 1] == t[j - 1] {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Convert result to i32 (safe because it's a count)
        dp[m][n] as i32
    }
}
//sub: https://leetcode.com/problems/distinct-subsequences/submissions/1557735762/
//sol: https://leetcode.com/problems/distinct-subsequences/solutions/6476059/115-distinct-subsequences-by-nalindalal2-8ksp/
