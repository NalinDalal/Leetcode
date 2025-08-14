//2264. Largest 3-Same-Digit Number in String
impl Solution {
    pub fn largest_good_integer(num: String) -> String {
        let chars: Vec<char> = num.chars().collect();
        let mut ans = String::new();

        for i in 0..chars.len().saturating_sub(2) {
            if chars[i] == chars[i + 1] && chars[i] == chars[i + 2] {
                let triplet: String = chars[i..=i + 2].iter().collect();
                if triplet > ans {
                    ans = triplet;
                }
            }
        }

        ans
    }
}
//sub: https://leetcode.com/problems/largest-3-same-digit-number-in-string/submissions/1734435893/?envType=daily-question&envId=2025-08-14
//sol: https://leetcode.com/problems/largest-3-same-digit-number-in-string/solutions/7077957/2264-largest-3-same-digit-number-in-stri-r0lp/
