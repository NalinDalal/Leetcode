//2140. Solving Questions With Brainpower
impl Solution {
    pub fn most_points(questions: Vec<Vec<i32>>) -> i64 {
        let n = questions.len();
        let mut dp = vec![0; n + 1];

        for i in (0..n).rev() {
            let points = questions[i][0] as i64;
            let brainpower = questions[i][1] as usize;
            let next_index = i + 1 + brainpower;

            let take = points + if next_index < n { dp[next_index] } else { 0 };
            let skip_question = dp[i + 1];

            dp[i] = take.max(skip_question);
        }

        dp[0]
    }
}
//sub: https://leetcode.com/problems/solving-questions-with-brainpower/submissions/1592884836/?envType=daily-question&envId=2025-04-01
//sol: https://leetcode.com/problems/solving-questions-with-brainpower/solutions/6602804/2140-solving-questions-with-brainpower-b-y02n/
