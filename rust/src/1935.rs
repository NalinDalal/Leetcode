//1935. Maximum Number of Words You Can Type
impl Solution {
    pub fn can_be_typed_words(text: String, broken_letters: String) -> i32 {
        use std::collections::HashSet;

        let broken: HashSet<char> = broken_letters.chars().collect();
        let mut ans = 0;

        for word in text.split_whitespace() {
            if !word.chars().any(|c| broken.contains(&c)) {
                ans += 1;
            }
        }

        ans
    }
}
//sub: https://leetcode.com/problems/maximum-number-of-words-you-can-type/submissions/1771048059/?envType=daily-question&envId=2025-09-15
//sol: https://leetcode.com/problems/maximum-number-of-words-you-can-type/solutions/7190686/1935-maximum-number-of-words-you-can-typ-zy8j/
