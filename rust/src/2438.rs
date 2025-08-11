//2438. Range Product Queries of Powers
impl Solution {
    const MOD: i64 = 1_000_000_007;

    fn mod_pow(mut base: i64, mut exp: i64) -> i64 {
        let mut res = 1i64;
        base %= Self::MOD;
        while exp > 0 {
            if exp & 1 == 1 {
                res = (res * base) % Self::MOD;
            }
            base = (base * base) % Self::MOD;
            exp >>= 1;
        }
        res
    }

    pub fn product_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        // Extract powers of two
        let mut powers = Vec::new();
        let mut num = n;
        let mut bit = 0;
        while num > 0 {
            if num & 1 == 1 {
                powers.push(1 << bit);
            }
            bit += 1;
            num >>= 1;
        }

        // Prefix products
        let mut prefix = vec![1i64];
        for &p in &powers {
            let last = *prefix.last().unwrap();
            prefix.push((last * p as i64) % Self::MOD);
        }

        // Answer queries
        let mut ans = Vec::new();
        for q in queries {
            let l = q[0] as usize;
            let r = q[1] as usize;
            let numerator = prefix[r + 1];
            let denominator_inv = Self::mod_pow(prefix[l], Self::MOD - 2);
            ans.push(((numerator * denominator_inv) % Self::MOD) as i32);
        }

        ans
    }
}
//sub: https://leetcode.com/problems/range-product-queries-of-powers/submissions/1730703634/?envType=daily-question&envId=2025-08-11
//sol: https://leetcode.com/problems/range-product-queries-of-powers/solutions/7066250/2438-range-product-queries-of-powers-by-lr4bn/
