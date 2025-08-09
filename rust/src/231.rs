//231. Power of Two
impl Solution{
    pub fn is_power_of_two(n: i32) -> bool {
        n > 0 && (n & (n - 1)) == 0
    }
}
//sub: https://leetcode.com/problems/power-of-two/submissions/1728582576/?envType=daily-question&envId=2025-08-09
//sol: https://leetcode.com/problems/power-of-two/solutions/7059789/231-power-of-two-by-nalindalal2004-fv57/
