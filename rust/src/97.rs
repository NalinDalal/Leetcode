//97. Interleaving String
impl Solution {
    pub fn is_interleave(s1: String, s2: String, s3: String) -> bool {
        let n1 = s1.len();
        let n2 = s2.len();
        let n3 = s3.len();

        if n1 + n2 != n3 {
            return false;
        }

        if n1 < n2 {
            return Self::is_interleave(s2, s1, s3);
        }

        let s1: Vec<char> = s1.chars().collect();
        let s2: Vec<char> = s2.chars().collect();
        let s3: Vec<char> = s3.chars().collect();

        let mut dp = vec![false; n2 + 1];
        dp[0] = true;

        for j in 1..=n2 {
            dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
        }

        for i in 1..=n1 {
            dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
            for j in 1..=n2 {
                dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1])
                    || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        dp[n2]
    }
}
//sub: https://leetcode.com/problems/interleaving-string/submissions/1556666739/
//sol: https://leetcode.com/problems/interleaving-string/solutions/6472507/97-interleaving-string-by-nalindalal2004-aqgb/
