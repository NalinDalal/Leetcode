//1092. Shortest Common Supersequence

impl Solution {
    pub fn shortest_common_supersequence(a: String, b: String) -> String {
        let m = a.len();
        let n = b.len();
        let a = a.as_bytes();
        let b = b.as_bytes();

        // DP table for Longest Common Subsequence (LCS)
        let mut dp = vec![vec![0; n + 1]; m + 1];

        for i in 0..m {
            for j in 0..n {
                dp[i + 1][j + 1] = if a[i] == b[j] {
                    dp[i][j] + 1
                } else {
                    dp[i][j + 1].max(dp[i + 1][j])
                };
            }
        }

        let mut res = Vec::new();
        let (mut i, mut j) = (m, n);

        // Constructing the shortest common supersequence (SCS)
        while i > 0 && j > 0 {
            if dp[i][j] == dp[i - 1][j] {
                res.push(a[i - 1] as char);
                i -= 1;
            } else if dp[i][j] == dp[i][j - 1] {
                res.push(b[j - 1] as char);
                j -= 1;
            } else {
                res.push(a[i - 1] as char);
                i -= 1;
                j -= 1;
            }
        }

        // Append remaining characters in order
        while i > 0 {
            res.push(a[i - 1] as char);
            i -= 1;
        }
        while j > 0 {
            res.push(b[j - 1] as char);
            j -= 1;
        }

        res.reverse();
        res.iter().collect()
    }
}

//sub:https://leetcode.com/problems/shortest-common-supersequence/submissions/1557743809/?envType=daily-question&envId=2025-02-28
//sol: https://leetcode.com/problems/shortest-common-supersequence/solutions/6476094/1092-shortest-common-supersequence-by-na-tt01/
