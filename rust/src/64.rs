//64. Minimum Path Sum

impl Solution {
    pub fn min_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut dp = vec![vec![0; n]; m];

        dp[0][0] = grid[0][0];

        for i in 1..m {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for j in 1..n {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for i in 1..m {
            for j in 1..n {
                dp[i][j] = dp[i - 1][j].min(dp[i][j - 1]) + grid[i][j];
            }
        }

        dp[m - 1][n - 1]
    }
}

//sub: https://leetcode.com/problems/minimum-path-sum/submissions/1603223788/
//sol: https://leetcode.com/problems/minimum-path-sum/solutions/6638112/64-minimum-path-sum-by-nalindalal2004-4lup/
