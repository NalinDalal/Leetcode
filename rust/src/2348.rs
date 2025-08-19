//2348. Number of Zero-Filled Subarrays
impl Solution {
    pub fn zero_filled_subarray(nums: Vec<i32>) -> i64 {
        let mut count: i64 = 0;
        let mut streak: i64 = 0;

        for &n in &nums {
            if n == 0 {
                streak += 1;
                count += streak;
            } else {
                streak = 0;
            }
        }

        count
    }
}
//sub: https://leetcode.com/problems/number-of-zero-filled-subarrays/submissions/1740253192/?envType=daily-question&envId=2025-08-19
//sol: https://leetcode.com/problems/number-of-zero-filled-subarrays/solutions/7097173/2348-number-of-zero-filled-subarrays-by-mk9bb/
