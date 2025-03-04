//1780. Check if Number is a Sum of Powers of Three
impl Solution {
    pub fn check_powers_of_three(mut n: i32) -> bool {
        while n > 0 {
            if n % 3 == 2 {
                return false;
            }
            n /= 3;
        }
        true
    }
}
//sub: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/submissions/1562351104/?envType=daily-question&envId=2025-03-04
//sol: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/solutions/6494146/1780-check-if-number-is-a-sum-of-powers-eaxgf/
