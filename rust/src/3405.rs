//3405. Count the Number of Arrays with K Matching Adjacent Elements
impl Solution {
    pub fn count_good_arrays(n: i32, m: i32, k: i32) -> i32 {
        const MOD: i64 = 1_000_000_007;

        fn mod_pow(mut a: i64, mut b: i64) -> i64 {
            a %= MOD;
            let mut result = 1;
            while b > 0 {
                if b & 1 == 1 {
                    result = result * a % MOD;
                }
                a = a * a % MOD;
                b >>= 1;
            }
            result
        }

        struct Combinatorics {
            fact: Vec<i64>,
            inv: Vec<i64>,
            inv_fact: Vec<i64>,
        }

        impl Combinatorics {
            fn new() -> Self {
                Self {
                    fact: vec![1, 1],
                    inv: vec![1, 1],
                    inv_fact: vec![1, 1],
                }
            }

            fn ensure(&mut self, n: usize) {
                while self.fact.len() <= n {
                    let i = self.fact.len();
                    self.fact.push(self.fact[i - 1] * i as i64 % MOD);
                    self.inv
                        .push(self.inv[MOD as usize % i] * (MOD - MOD / i as i64) % MOD);
                    self.inv_fact.push(self.inv_fact[i - 1] * self.inv[i] % MOD);
                }
            }

            fn ncr(&mut self, n: usize, k: usize) -> i64 {
                if k > n {
                    return 0;
                }
                self.ensure(n);
                self.fact[n] * self.inv_fact[n - k] % MOD * self.inv_fact[k] % MOD
            }
        }

        let (n, m, k) = (n as usize, m as i64, k as usize);
        let mut comb = Combinatorics::new();
        let c = comb.ncr(n - 1, k);
        let pow = mod_pow(m - 1, (n - 1 - k) as i64);
        (c * m % MOD * pow % MOD) as i32
    }
}
//sub: https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/submissions/1666684835/?envType=daily-question&envId=2025-06-17
//sol: https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/solutions/6852435/3405-count-the-number-of-arrays-with-k-m-3sli/
