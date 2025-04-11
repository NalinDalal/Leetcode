//2843. Count Symmetric Integers
impl Solution {
    pub fn count_symmetric_integers(low: i32, high: i32) -> i32 {
        let mut count = 0;

        for x in low..=high {
            let s = x.to_string();
            let len = s.len();

            if len % 2 != 0 {
                continue;
            }

            let half = len / 2;
            let sum1: i32 = s[..half]
                .chars()
                .map(|c| c.to_digit(10).unwrap() as i32)
                .sum();
            let sum2: i32 = s[half..]
                .chars()
                .map(|c| c.to_digit(10).unwrap() as i32)
                .sum();

            if sum1 == sum2 {
                count += 1;
            }
        }

        count
    }
}
//sub: https://leetcode.com/problems/count-symmetric-integers/submissions/1603232692/?envType=daily-question&envId=2025-04-11
//sol: https://leetcode.com/problems/count-symmetric-integers/solutions/6638140/2843-count-symmetric-integers-by-nalinda-w38p/
