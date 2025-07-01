//3330. Find the Original Typed String I
impl Solution {
    pub fn possible_string_count(word: String) -> i32 {
        let mut ans = 1;
        let chars: Vec<char> = word.chars().collect();
        for i in 1..chars.len() {
            if chars[i - 1] == chars[i] {
                ans += 1;
            }
        }
        ans
    }
}
//sub: https://leetcode.com/problems/find-the-original-typed-string-i/submissions/1682794468/
// sol: https://leetcode.com/problems/find-the-original-typed-string-i/solutions/6907639/3330-find-the-original-typed-string-i-by-lyxp/
