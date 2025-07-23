//1717. Maximum Score From Removing Substrings
impl Solution {
    pub fn remove_substr(s: &str, first: char, second: char, gain: i32) -> (String, i32) {
        let mut stack = Vec::new();
        let mut score = 0;

        for c in s.chars() {
            if let Some(&last) = stack.last() {
                if last == first && c == second {
                    stack.pop();
                    score += gain;
                    continue;
                }
            }
            stack.push(c);
        }

        let remaining: String = stack.into_iter().collect();
        (remaining, score)
    }

    pub fn maximum_gain(mut s: String, x: i32, y: i32) -> i32 {
        let mut total_score = 0;

        if x > y {
            let (s1, score1) = Self::remove_substr(&s, 'a', 'b', x);
            let (s2, score2) = Self::remove_substr(&s1, 'b', 'a', y);
            total_score = score1 + score2;
        } else {
            let (s1, score1) = Self::remove_substr(&s, 'b', 'a', y);
            let (s2, score2) = Self::remove_substr(&s1, 'a', 'b', x);
            total_score = score1 + score2;
        }

        total_score
    }
}
// Example:
fn main() {
    let result = maximum_gain("cdbcbbaaabab".to_string(), 4, 5);
    println!("{}", result); // Output: 19
}

//sub: https://leetcode.com/problems/maximum-score-from-removing-substrings/submissions/1708302193/?envType=daily-question&envId=2025-07-23
//sol: https://leetcode.com/problems/maximum-score-from-removing-substrings/solutions/6994176/1717-maximum-score-from-removing-substri-excy/
