//1695. Maximum Erasure Value
use std::collections::HashSet;
impl Solution {
    pub fn maximum_unique_subarray(nums: Vec<i32>) -> i32 {
        let mut seen = HashSet::new();
        let mut left = 0;
        let mut curr_sum = 0;
        let mut max_sum = 0;

        for right in 0..nums.len() {
            while seen.contains(&nums[right]) {
                seen.remove(&nums[left]);
                curr_sum -= nums[left];
                left += 1;
            }
            seen.insert(nums[right]);
            curr_sum += nums[right];
            max_sum = max_sum.max(curr_sum);
        }

        max_sum
    }
}
//sub: https://leetcode.com/problems/maximum-erasure-value/submissions/1707147510/
//sol: https://leetcode.com/problems/maximum-erasure-value/solutions/6990314/1695-maximum-erasure-value-by-nalindalal-l3ep/
