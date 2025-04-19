//2563. Count the Number of Fair Pairs
impl Solution {
    pub fn count_fair_pairs(mut nums: Vec<i32>, lower: i32, upper: i32) -> i64 {
        nums.sort();
        let mut count = 0_i64;

        for i in 0..nums.len() {
            let low = Self::lower_bound(&nums, lower - nums[i], i + 1);
            let high = Self::upper_bound(&nums, upper - nums[i], i + 1);
            count += (high - low) as i64;
        }

        count
    }

    pub fn lower_bound(nums: &[i32], target: i32, start: usize) -> usize {
        let mut left = start;
        let mut right = nums.len();
        while left < right {
            let mid = (left + right) / 2;
            if nums[mid] < target {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        left
    }

    pub fn upper_bound(nums: &[i32], target: i32, start: usize) -> usize {
        let mut left = start;
        let mut right = nums.len();
        while left < right {
            let mid = (left + right) / 2;
            if nums[mid] <= target {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        left
    }
}
//sub: https://leetcode.com/problems/count-the-number-of-fair-pairs/submissions/1611127871/?envType=daily-question&envId=2025-04-19
//sol: https://leetcode.com/problems/count-the-number-of-fair-pairs/solutions/6665669/2563-count-the-number-of-fair-pairs-by-n-rk8n/
