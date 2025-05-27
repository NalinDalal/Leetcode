//2894. Divisible and Non-divisible Sums Difference
impl Solution {
    pub fn difference_of_sums(n: i32, m: i32) -> i32 {
        let mut num1 = 0;
        let mut num2 = 0;

        for i in 1..=n {
            if i % m == 0 {
                num2 += i;
            } else {
                num1 += i;
            }
        }

        num1 - num2
    }
}
//sub: https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/submissions/1645570796/?envType=daily-question&envId=2025-05-27
//sol: https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/solutions/6785007/2894-divisible-and-non-divisible-sums-di-qwpv/
