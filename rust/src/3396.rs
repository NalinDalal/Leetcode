//3396. Minimum Number of Operations to Make Elements in Array Distinct

use std::collections::HashSet;

impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        let mut ops = 0;
        let mut start = 0;

        while start < nums.len() {
            let mut seen = HashSet::new();
            let mut has_duplicates = false;

            for &num in &nums[start..] {
                if !seen.insert(num) {
                    has_duplicates = true;
                    break;
                }
            }

            if !has_duplicates {
                break;
            }

            start += 3;
            ops += 1;
        }

        ops
    }
}
//sub: https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/submissions/1600180957/?envType=daily-question&envId=2025-04-08
//sol: https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/solutions/6627455/3396-minimum-number-of-operations-to-mak-4fwt/
