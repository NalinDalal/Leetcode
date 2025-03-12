//2529. Maximum Count of Positive Integer and Negative Integer
use std::cmp::max;

impl Solution {
    pub fn maximum_count(nums: Vec<i32>) -> i32 {
        let mut pos_cnt: i32 = 0;
        let mut neg_cnt: i32 = 0;

        for num in nums.iter() {
            if *num < 0 {
                neg_cnt += 1;
            } else if *num > 0 {
                pos_cnt += 1;
            }
        }

        max(pos_cnt, neg_cnt)
    }
}
//sub: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/submissions/1570890605/?envType=daily-question&envId=2025-03-12
//sol: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/solutions/6526440/2529-maximum-count-of-positive-integer-a-8v3d/
