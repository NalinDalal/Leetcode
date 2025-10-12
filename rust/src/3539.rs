//3539. Find Sum of Array Product of Magical Sequences
impl Solution {
    pub fn magical_sum(m: i32, k: i32, nums: Vec<i32>) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let m_usize = m as usize;
        let k_usize = k as usize;
        let n = nums.len();

        // factorials and invfact
        let mut fact = vec![1i64; m_usize + 1];
        for i in 1..=m_usize {
            fact[i] = fact[i - 1] * (i as i64) % MOD;
        }
        let mut invfact = vec![1i64; m_usize + 1];
        // powmod
        let mut mod_pow = |mut base: i64, mut exp: i64| -> i64 {
            base %= MOD;
            if base < 0 { base += MOD; }
            let mut r = 1i64;
            while exp > 0 {
                if exp & 1 == 1 { r = (r * base) % MOD; }
                base = (base * base) % MOD;
                exp >>= 1;
            }
            r
        };
        invfact[m_usize] = mod_pow(fact[m_usize], MOD - 2);
        for i in (1..=m_usize).rev() {
            invfact[i - 1] = invfact[i] * (i as i64) % MOD;
        }

        // pow_nums[pos][c] = nums[pos]^c % MOD
        let mut pow_nums: Vec<Vec<i64>> = vec![vec![0; m_usize + 1]; n];
        for i in 0..n {
            pow_nums[i][0] = 1;
            let val = (nums[i] as i64) % MOD;
            for c in 1..=m_usize {
                pow_nums[i][c] = (pow_nums[i][c - 1] * val) % MOD;
            }
        }

        // extra bits
        let extra = ((m as f64).log2().floor() as usize).saturating_add(3);
        let total_bits = n + extra;

        // dp[used][carry][ones]
        let mut dp = vec![vec![vec![0i64; k_usize + 1]; m_usize + 1]; m_usize + 1];
        dp[0][0][0] = 1;

        for pos in 0..total_bits {
            let mut ndp = vec![vec![vec![0i64; k_usize + 1]; m_usize + 1]; m_usize + 1];
            for used in 0..=m_usize {
                for carry in 0..=m_usize {
                    for ones in 0..=k_usize {
                        let cur = dp[used][carry][ones];
                        if cur == 0 { continue; }
                        let maxc = if pos < n { m_usize - used } else { 0 };
                        for take in 0..=maxc {
                            let total = carry + take;
                            let bit = total & 1;
                            let carry_next = total >> 1;
                            if carry_next > m_usize { continue; }
                            let ones_next = ones + bit;
                            if ones_next > k_usize { continue; }

                            let mut mult = cur;
                            if take > 0 {
                                mult = mult * pow_nums[pos][take] % MOD;
                                mult = mult * invfact[take] % MOD;
                            }
                            let target = &mut ndp[used + take][carry_next][ones_next];
                            *target = (*target + mult) % MOD;
                        }
                    }
                }
            }
            dp = ndp;
        }

        let ans_unordered = dp[m_usize][0][k_usize];
        let ans = ans_unordered * fact[m_usize] % MOD;
        ((ans % MOD + MOD) % MOD) as i32
    }
}

//sub: https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/submissions/1799128787/?envType=daily-question&envId=2025-10-12
//sol: https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/solutions/7268694/3539-find-sum-of-array-product-of-magica-0509/
