//392. Is Subsequence

impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        let (mut i, mut j) = (0, 0);
        let s_chars: Vec<char> = s.chars().collect();
        let t_chars: Vec<char> = t.chars().collect();

        while i < s_chars.len() && j < t_chars.len() {
            if s_chars[i] == t_chars[j] {
                i += 1;
            }
            j += 1;
        }

        i == s_chars.len()
    }
}
//sub: https://leetcode.com/problems/is-subsequence/submissions/1594060955/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/is-subsequence/solutions/6606224/392-is-subsequence-by-nalindalal2004-egtt/
