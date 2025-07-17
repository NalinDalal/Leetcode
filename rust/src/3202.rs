//3202. Find the Maximum Length of Valid Subsequence II
impl Solution {
    pub fn maximum_length(nums: Vec<i32>, k: i32) -> i32 {
        let mut ans = 0;
        let k = k as usize;

        for val in 0..k {
            let mut dp = vec![0; k];
            for &x in &nums {
                let modx = (x % k as i32 + k as i32) % k as i32;
                let required_prev_mod = ((val as i32 - modx + k as i32) % k as i32) as usize;
                let mod_idx = modx as usize;
                dp[mod_idx] = dp[mod_idx].max(dp[required_prev_mod] + 1);
                ans = ans.max(dp[mod_idx]);
            }
        }

        ans
    }
}

//sub: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/submissions/1700909950/
//sol: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/solutions/6969313/3202-find-the-maximum-length-of-valid-su-kfj0/
