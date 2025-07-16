//3201. Find the Maximum Length of Valid Subsequence I
impl Solution {
    pub fn maximum_length(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        let patterns = vec![vec![0, 0], vec![0, 1], vec![1, 0], vec![1, 1]];
        for pattern in patterns {
            let mut cnt = 0;
            for num in &nums {
                if num % 2 == pattern[cnt % 2] {
                    cnt += 1;
                }
            }
            res = res.max(cnt);
        }
        res as i32
    }
}
//sub: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/submissions/1700025858/?envType=daily-question&envId=2025-07-16
//sol: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/solutions/6966556/3201-find-the-maximum-length-of-valid-su-tu7u/
