//9. Palindrome Number
impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 {
            return false;
        }

        let mut n = x;
        let mut sum: i32 = 0;

        while n > 0 {
            // Check for potential overflow (optional)
            match sum.checked_mul(10).and_then(|s| s.checked_add(n % 10)) {
                Some(val) => sum = val,
                None => return false, // overflow => not palindrome
            }
            n /= 10;
        }

        sum == x
    }
}
//sub: https://leetcode.com/problems/palindrome-number/submissions/1605358364/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/palindrome-number/solutions/6645490/9-palindrome-number-by-nalindalal2004-fmgc/
