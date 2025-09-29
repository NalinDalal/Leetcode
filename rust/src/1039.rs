//1039. Minimum Score Triangulation of Polygon
impl Solution {
    pub fn min_score_triangulation(values: Vec<i32>) -> i32 {
        let n = values.len();
        let mut dp = vec![vec![0; n]; n];

        for gap in 2..n {
            for i in 0..n - gap {
                let j = i + gap;
                dp[i][j] = i32::MAX;
                for k in i + 1..j {
                    dp[i][j] = dp[i][j].min(
                        dp[i][k] + dp[k][j] + values[i] * values[j] * values[k],
                    );
                }
            }
        }

        dp[0][n - 1]
    }
}
//sub: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/submissions/1786013850/?envType=daily-question&envId=2025-09-29
//sol: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/solutions/7232926/1039-minimum-score-triangulation-of-poly-66z1/
