//1922. Count Good Numbers
impl Solution {
    pub fn count_good_numbers(n: i64) -> i32 {
        const MOD: i64 = 1_000_000_007;

        fn power(mut base: i64, mut exp: i64) -> i64 {
            let mut result = 1;
            base %= MOD;

            while exp > 0 {
                if exp % 2 == 1 {
                    result = (result * base) % MOD;
                }
                base = (base * base) % MOD;
                exp /= 2;
            }

            result
        }

        let even = (n + 1) / 2;
        let odd = n / 2;

        let result = (power(5, even) * power(4, odd)) % MOD;
        result as i32
    }
}
//sub:https://leetcode.com/problems/count-good-numbers/submissions/1605367587/?envType=daily-question&envId=2025-04-13
//sol:https://leetcode.com/problems/count-good-numbers/solutions/6645571/1922-count-good-numbers-by-nalindalal200-994j/
