//3343. Count Number of Balanced Permutations

const MOD: i64 = 1_000_000_007;

impl Solution {
    pub fn count_balanced_permutations(num: String) -> i32 {
        let n = num.len();
        let mut cnt = [0; 10];
        let mut tot = 0;

        for ch in num.chars() {
            let d = ch.to_digit(10).unwrap() as usize;
            cnt[d] += 1;
            tot += d as i32;
        }

        if tot % 2 != 0 {
            return 0;
        }

        let target = tot / 2;
        let max_odd = (n + 1) / 2;

        let mut comb = vec![vec![0i64; max_odd + 1]; max_odd + 1];
        for i in 0..=max_odd {
            comb[i][0] = 1;
            comb[i][i] = 1;
            for j in 1..i {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }

        let mut psum = [0; 11];
        for i in (0..10).rev() {
            psum[i] = psum[i + 1] + cnt[i];
        }

        let mut memo = vec![vec![vec![-1; max_odd + 1]; (target + 1) as usize]; 10];

        fn dfs(
            pos: usize,
            curr: i32,
            odd_cnt: usize,
            cnt: &[i32; 10],
            psum: &[i32; 11],
            comb: &Vec<Vec<i64>>,
            memo: &mut Vec<Vec<Vec<i64>>>,
            target: i32,
        ) -> i64 {
            if odd_cnt as i32 > psum[pos] || curr > target {
                return 0;
            }
            if pos > 9 {
                return if curr == target && odd_cnt == 0 { 1 } else { 0 };
            }
            if memo[pos][curr as usize][odd_cnt] != -1 {
                return memo[pos][curr as usize][odd_cnt];
            }

            let even_cnt = (psum[pos] - odd_cnt as i32) as usize;
            let mut res = 0;

            let min_i = cnt[pos].saturating_sub(even_cnt as i32);
            let max_i = cnt[pos].min(odd_cnt as i32);

            if min_i <= max_i {
                for i in min_i..=max_i {
                    let i_usize = i as usize;
                    let j_usize = cnt[pos].saturating_sub(i) as usize;

                    if i_usize > odd_cnt || j_usize > even_cnt {
                        continue;
                    }

                    let ways = comb[odd_cnt][i_usize] * comb[even_cnt][j_usize] % MOD;
                    let sub = dfs(
                        pos + 1,
                        curr + (i * pos as i32),
                        odd_cnt - i_usize,
                        cnt,
                        psum,
                        comb,
                        memo,
                        target,
                    );
                    res = (res + ways * sub % MOD) % MOD;
                }
            }

            memo[pos][curr as usize][odd_cnt] = res;
            res
        }

        dfs(0, 0, max_odd, &cnt, &psum, &comb, &mut memo, target) as i32
    }
}
//sub: https://leetcode.com/problems/count-number-of-balanced-permutations/submissions/1629303863/?envType=daily-question&envId=2025-05-09
