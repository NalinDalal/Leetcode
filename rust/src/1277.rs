//1277. Count Square Submatrices with All Ones
impl Solution {
    pub fn count_squares(matrix: Vec<Vec<i32>>) -> i32 {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut dp = vec![vec![0; n]; m];
        let mut total = 0;

        for i in 0..m {
            for j in 0..n {
                if matrix[i][j] == 1 {
                    if i == 0 || j == 0 {
                        dp[i][j] = 1; // first row/col
                    } else {
                        dp[i][j] = 1 + dp[i - 1][j]
                            .min(dp[i][j - 1])
                            .min(dp[i - 1][j - 1]);
                    }
                    total += dp[i][j];
                }
            }
        }
        total
    }
}
//sub: https://leetcode.com/problems/count-square-submatrices-with-all-ones/submissions/1741546159/?envType=daily-question&envId=2025-08-20
//sol: https://leetcode.com/problems/count-square-submatrices-with-all-ones/solutions/7101654/1277-count-square-submatrices-with-all-o-t6k5/
