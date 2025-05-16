//2901. Longest Unequal Adjacent Groups Subsequence II

impl Solution {
    pub fn get_words_in_longest_subsequence(words: Vec<String>, groups: Vec<i32>) -> Vec<String> {
        let n = groups.len();
        let mut dp = vec![1; n];
        let mut prev = vec![-1; n];
        let mut max_index = 0;
        for i in 1..n {
            for j in 0..i {
                if Self::check(&words[i], &words[j]) && dp[j] + 1 > dp[i] && groups[i] != groups[j]
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j as i32;
                }
            }
            if dp[i] > dp[max_index] {
                max_index = i;
            }
        }
        let mut ans = Vec::new();
        let mut i = max_index as i32;
        while i >= 0 {
            ans.push(words[i as usize].clone());
            i = prev[i as usize];
        }
        ans.reverse();
        ans
    }

    fn check(s1: &String, s2: &String) -> bool {
        if s1.len() != s2.len() {
            return false;
        }
        let mut diff = 0;
        for (c1, c2) in s1.chars().zip(s2.chars()) {
            if c1 != c2 {
                diff += 1;
                if diff > 1 {
                    return false;
                }
            }
        }
        diff == 1
    }
}

//sub: https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/submissions/1635248978/?envType=daily-question&envId=2025-05-16

impl Solution {
    pub fn get_words_in_longest_subsequence(words: Vec<String>, groups: Vec<i32>) -> Vec<String> {
        let n = words.len();
        let mut dp = vec![1; n];
        let mut prev = vec![-1; n];
        let mut max_index = 0;

        for i in 1..n {
            let s1 = words[i].as_bytes();
            for j in 0..i {
                if groups[i] == groups[j] {
                    continue;
                }

                let s2 = words[j].as_bytes();
                if s1.len() != s2.len() {
                    continue;
                }

                let mut diff = 0;
                for (&a, &b) in s1.iter().zip(s2.iter()) {
                    if a != b {
                        diff += 1;
                        if diff > 1 {
                            break;
                        }
                    }
                }

                if diff == 1 && dp[j] + 1 > dp[i] {
                    dp[i] = dp[j] + 1;
                    prev[i] = j as i32;
                }
            }
            if dp[i] > dp[max_index] {
                max_index = i;
            }
        }

        // Trace back the path using prev[]
        let mut result = Vec::new();
        let mut i = max_index as i32;
        while i >= 0 {
            result.push(words[i as usize].clone());
            i = prev[i as usize];
        }
        result.reverse();
        result
    }
}
//sub: https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/submissions/1635249835/?envType=daily-question&envId=2025-05-16
