//371. Sum of Two Integers
impl Solution {
    pub fn get_sum(a: i32, b: i32) -> i32 {
        let mut x = a ^ b; // xor for sum
        let mut y = (a & b) << 1; // & for carry

        while y != 0 {
            let car = (x & y) << 1;
            x ^= y;
            y = car;
        }

        x
    }
}
//sub: https://leetcode.com/problems/sum-of-two-integers/submissions/1577500011/
//sol: https://leetcode.com/problems/sum-of-two-integers/solutions/6549813/371-sum-of-two-integers-by-nalindalal200-5brn/
