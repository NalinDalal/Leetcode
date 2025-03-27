//172. Factorial Trailing
impl Solution {
    pub fn trailing_zeroes(mut n: i32) -> i32 {
        let mut count = 0;
        while n >= 5 {
            count += n / 5;
            n /= 5;
        }
        count
    }
}
//sub: https://leetcode.com/problems/factorial-trailing-zeroes/submissions/1587712112/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/factorial-trailing-zeroes/solutions/6584573/172-factorial-trailing-zeroes-by-nalinda-ckpm/
