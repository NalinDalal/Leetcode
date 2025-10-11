//120. Triangle
impl Solution {
    pub fn minimum_total(triangle: Vec<Vec<i32>>) -> i32 {
        let mut dp = triangle.last().unwrap().clone(); // start with last row

        // move from second last row to the top
        for i in (0..triangle.len() - 1).rev() {
            for j in 0..triangle[i].len() {
                dp[j] = triangle[i][j] + dp[j].min(dp[j + 1]);
            }
        }

        dp[0]
    }
}
//sub: https://leetcode.com/problems/triangle/submissions/1781860736/?envType=daily-question&envId=2025-09-25
//sol: https://leetcode.com/problems/triangle/solutions/6233375/120-triangle100-by-nalindalal2004-i6j4/
