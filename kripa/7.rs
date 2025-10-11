//7. Reverse Integer
pub struct Solution;

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let is_negative = x < 0;
        let mut num_str: String = x.abs().to_string();
        num_str = num_str.chars().rev().collect();

        if let Ok(mut reversed) = num_str.parse::<i32>() {
            if is_negative {
                reversed = -reversed;
            }
            return reversed;
        }

        0 // Return 0 in case of overflow
    }
}

fn main() {
    println!("{}", Solution::reverse(123)); // 321
    println!("{}", Solution::reverse(-123)); // -321
    println!("{}", Solution::reverse(120)); // 21
    println!("{}", Solution::reverse(0)); // 0
    println!("{}", Solution::reverse(1534236469)); // 0 (Overflow)
}
//sub: https://leetcode.com/problems/reverse-integer/submissions/1578673274/
//sol: https://leetcode.com/problems/reverse-integer/solutions/6553948/7-reverse-integer-by-nalindalal2004-aaij/
