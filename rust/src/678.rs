//678. Valid Parenthesis String
impl Solution {
    pub fn check_valid_string(s: String) -> bool {
        let mut min_left = 0;
        let mut max_left = 0;

        for c in s.chars() {
            match c {
                '(' => {
                    min_left += 1;
                    max_left += 1;
                }
                ')' => {
                    if min_left > 0 {
                        min_left -= 1;
                    }
                    max_left -= 1;
                }
                '*' => {
                    if min_left > 0 {
                        min_left -= 1; // Treat '*' as ')'
                    }
                    max_left += 1; // Treat '*' as '('
                }
                _ => {}
            }

            if max_left < 0 {
                return false; // Too many ')' without matching '('
            }
        }

        min_left == 0
    }
}
//sub: https://leetcode.com/problems/valid-parenthesis-string/submissions/1569756833/
//sol: https://leetcode.com/problems/valid-parenthesis-string/solutions/6522267/678-valid-parenthesis-string-by-nalindal-30s8/
