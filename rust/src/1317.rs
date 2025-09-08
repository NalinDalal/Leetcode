//1317. Convert Integer to the Sum of Two No-Zero Integers
impl Solution {
    pub fn get_no_zero_integers(n: i32) -> Vec<i32> {
        for i in 1..n {
            let a = i;
            let b = n - i;
            if is_no_zero(a) && is_no_zero(b) {
                return vec![a, b];
            }
        }
        vec![]
    }
}

fn is_no_zero(mut x: i32) -> bool {
    while x > 0 {
        if x % 10 == 0 {
            return false;
        }
        x /= 10;
    }
    true
}

//sub: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/submissions/1763232661/?envType=daily-question&envId=2025-09-08
//sol: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/solutions/7167137/1317-convert-integer-to-the-sum-of-two-n-7mop/
