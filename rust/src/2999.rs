//2999. Count the Number of Powerful Integers
impl Solution {
    pub fn number_of_powerful_int(start: i64, finish: i64, limit: i32, s: String) -> i64 {
        let low = format!("{:0width$}", start, width = finish.to_string().len());
        let high = finish.to_string();
        let n = high.len();
        let pre_len = n - s.len();
        let s_bytes = s.into_bytes(); // Convert String to Vec<u8>

        fn dfs(
            i: usize,
            limit_low: bool,
            limit_high: bool,
            low: &Vec<u8>,
            high: &Vec<u8>,
            s_bytes: &[u8],
            pre_len: usize,
            limit: u8,
            memo: &mut Vec<Option<i64>>,
        ) -> i64 {
            if i == low.len() {
                return 1;
            }

            if !limit_low && !limit_high {
                if let Some(val) = memo[i] {
                    return val;
                }
            }

            let lo = if limit_low { low[i] - b'0' } else { 0 };
            let hi = if limit_high { high[i] - b'0' } else { 9 };

            let mut res = 0;
            if i < pre_len {
                for digit in lo..=hi.min(limit) {
                    res += dfs(
                        i + 1,
                        limit_low && digit == lo,
                        limit_high && digit == hi,
                        low,
                        high,
                        s_bytes,
                        pre_len,
                        limit,
                        memo,
                    );
                }
            } else {
                let x = s_bytes[i - pre_len] - b'0';
                if x >= lo && x <= hi.min(limit) {
                    res += dfs(
                        i + 1,
                        limit_low && x == lo,
                        limit_high && x == hi,
                        low,
                        high,
                        s_bytes,
                        pre_len,
                        limit,
                        memo,
                    );
                }
            }

            if !limit_low && !limit_high {
                memo[i] = Some(res);
            }

            res
        }

        let low_bytes: Vec<u8> = low.bytes().collect();
        let high_bytes: Vec<u8> = high.bytes().collect();
        let mut memo = vec![None; n];

        dfs(
            0,
            true,
            true,
            &low_bytes,
            &high_bytes,
            &s_bytes,
            pre_len,
            limit as u8,
            &mut memo,
        )
    }
}
//sub: https://leetcode.com/problems/count-the-number-of-powerful-integers/submissions/1602573100/?envType=daily-question&envId=2025-04-10
//sol: https://leetcode.com/problems/count-the-number-of-powerful-integers/solutions/6636080/2999-count-the-number-of-powerful-intege-y4ye/
