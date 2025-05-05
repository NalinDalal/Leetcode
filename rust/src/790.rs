//790. Domino and Tromino Tiling

impl Solution {
    pub fn num_tilings(n: i32) -> i32 {
        let modulo = 1_000_000_007;
        if n < 3 {
            return [1, 1, 2][n as usize];
        }

        let (mut a0, mut a1, mut a2) = (1_i64, 1, 2);
        for _ in 3..=n {
            let x = (2 * a2 + a0) % modulo;
            a0 = a1;
            a1 = a2;
            a2 = x;
        }

        a2 as i32
    }
}
//sub: https://leetcode.com/problems/domino-and-tromino-tiling/submissions/1625825416/?envType=daily-question&envId=2025-05-05
