//2598. Smallest Missing Non-negative Integer After Operations
use std::collections::HashMap;

impl Solution {
    pub fn find_smallest_integer(nums: Vec<i32>, value: i32) -> i32 {
        let mut freq = HashMap::new();

        // Count frequency of normalized remainders
        for &x in &nums {
            let r = ((x % value) + value) % value; // handle negatives
            *freq.entry(r).or_insert(0) += 1;
        }

        let mut m = 0;
        loop {
            let r = m % value;
            let count = *freq.get(&r).unwrap_or(&0);

            if count == 0 {
                return m;
            }

            freq.insert(r, count - 1);
            m += 1;
        }
    }
}

//sub: https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/submissions/1803123926/?envType=daily-question&envId=2025-10-16
//sol: https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/solutions/7279095/2598-smallest-missing-non-negative-integ-xvdp/
