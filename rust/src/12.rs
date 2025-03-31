//12. Integer to Roman
impl Solution {
    pub fn int_to_roman(mut num: i32) -> String {
        let values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
        let symbols = [
            "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I",
        ];

        let mut result = String::new();
        let mut i = 0;

        while num > 0 {
            if num >= values[i] {
                result.push_str(symbols[i]);
                num -= values[i];
            } else {
                i += 1;
            }
        }

        result
    }
}
//sub: https://leetcode.com/problems/integer-to-roman/submissions/1591679669/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/integer-to-roman/solutions/6598547/12-integer-to-roman-by-nalindalal2004-k0zd/
