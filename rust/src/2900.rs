//2900. Longest Unequal Adjacent Groups Subsequence I
impl Solution {
    pub fn get_longest_subsequence(words: Vec<String>, groups: Vec<i32>) -> Vec<String> {
        let n = words.len();
        let mut dp = vec![1; n];
        let mut prev = vec![-1; n];
        let mut max_len = 1;
        let mut end_index = 0;

        for i in 1..n {
            let mut best_len = 1;
            let mut best_prev = -1;
            for j in (0..i).rev() {
                if groups[i] != groups[j] && dp[j] + 1 > best_len {
                    best_len = dp[j] + 1;
                    best_prev = j as i32;
                }
            }
            dp[i] = best_len;
            prev[i] = best_prev;
            if dp[i] > max_len {
                max_len = dp[i];
                end_index = i;
            }
        }

        let mut res = Vec::new();
        let mut i = end_index as i32;
        while i != -1 {
            res.push(words[i as usize].clone());
            i = prev[i as usize];
        }
        res.reverse();
        res
    }
}
//sub: https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/submissions/1634683196/?envType=daily-question&envId=2025-05-15
