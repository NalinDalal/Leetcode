//2434. Using a Robot to Print the Lexicographically Smallest String
impl Solution {
    pub fn robot_with_string(s: String) -> String {
        let n = s.len();
        let s_chars: Vec<char> = s.chars().collect();
        let mut t: Vec<char> = Vec::new();
        let mut p: Vec<char> = Vec::new();
        let mut min_right: Vec<char> = vec!['z'; n];

        // Build min_right array
        min_right[n - 1] = s_chars[n - 1];
        for i in (0..n - 1).rev() {
            min_right[i] = std::cmp::min(s_chars[i], min_right[i + 1]);
        }

        for i in 0..n {
            t.push(s_chars[i]);
            while !t.is_empty() && (i == n - 1 || *t.last().unwrap() <= min_right[i + 1]) {
                p.push(t.pop().unwrap());
            }
        }

        p.into_iter().collect()
    }
}
//sub: https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/submissions/1655315695/?envType=daily-question&envId=2025-06-06
