//2749. Minimum Operations to Make the Integer Zero
impl Solution {
    pub fn make_the_integer_zero(num1: i32, num2: i32) -> i32 {
        for k in 1..=60 {
            let x = num1 as i64 - k as i64 * num2 as i64;
            if x < k as i64 { continue; }

            let ones = x.count_ones();
            if ones as i64 <= k as i64 {
                return k;
            }
        }
        -1
    }
}
//sub: https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/submissions/1760033054/?envType=daily-question&envId=2025-09-05
//sol: https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/solutions/7157044/2749-minimum-operations-to-make-the-inte-t23n/
