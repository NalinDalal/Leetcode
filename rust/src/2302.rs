//2302. Count Subarrays With Score Less Than K

impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, k: i64) -> i64 {
        let mut ans: i64 = 0;
        let mut sum: i64 = 0;
        let mut left: usize = 0;

        for right in 0..nums.len() {
            sum += nums[right] as i64;

            while sum * (right as i64 - left as i64 + 1) >= k {
                sum -= nums[left] as i64;
                left += 1;
            }

            ans += (right as i64 - left as i64 + 1);
        }

        ans
    }
}
//sub: https://leetcode.com/problems/count-subarrays-with-score-less-than-k/submissions/1619879863/?envType=daily-question&envId=2025-04-28
