//440. K-th Smallest in Lexicographical Order
pub struct Solution;

impl Solution {
    pub fn find_kth_number(n: i32, k: i32) -> i32 {
        let mut k = k - 1;
        let mut curr = 1i64;

        while k > 0 {
            let steps = Self::count_steps(n as i64, curr, curr + 1);
            if steps <= k as i64 {
                curr += 1;
                k -= steps as i32;
            } else {
                curr *= 10;
                k -= 1;
            }
        }
        curr as i32
    }

    fn count_steps(n: i64, mut curr: i64, mut next: i64) -> i64 {
        let mut steps = 0;
        while curr <= n {
            steps += (n + 1).min(next) - curr;
            curr *= 10;
            next *= 10;
        }
        steps
    }
}
//sub: https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/submissions/1658228057/?envType=daily-question&envId=2025-06-09
