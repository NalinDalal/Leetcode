use std::collections::HashSet;

impl Solution {
    pub fn max_sum(nums: Vec<i32>) -> i32 {
        let mut seen = HashSet::new();
        let mut curr_sum = 0;
        let mut max_sum = i32::MIN;
        let mut last_sum = 0;

        for &num in &nums {
            if !seen.contains(&num) {
                curr_sum += num;
                max_sum = max_sum.max(curr_sum);
                if curr_sum < last_sum {
                    curr_sum = last_sum;
                }
                last_sum = curr_sum;
                seen.insert(num);
            }
        }

        max_sum
    }
}
//sub: https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/submissions/1711203636/?envType=daily-question&envId=2025-07-25
//sol: https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/solutions/7004277/3487-maximum-unique-subarray-sum-after-d-4jm7/
