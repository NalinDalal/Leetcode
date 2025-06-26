//2311. Longest Binary Subsequence Less Than or Equal to K
impl Solution {
    pub fn longest_subsequence(s: String, k: i32) -> i32 {
        let mut sm = 0;
        let mut cnt = 0;
        let bits = (k as f64).log2() as usize + 1;
        for (i, ch) in s.chars().rev().enumerate() {
            if ch == '1' {
                if i < bits && sm + (1 << i) <= k {
                    sm += 1 << i;
                    cnt += 1;
                }
            } else {
                cnt += 1;
            }
        }
        cnt
    }
}
//sub: https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/submissions/1676942004/?envType=daily-question&envId=2025-06-26
//sol: https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/solutions/6887180/2311-longest-binary-subsequence-less-tha-ornk/
