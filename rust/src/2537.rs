//2537. Count the Number of Good Subarrays

use std::collections::HashMap;

impl Solution {
    pub fn count_good(nums: Vec<i32>, k: i32) -> i64 {
        let mut freq = HashMap::new();
        let mut res = 0;
        let mut count_pairs: i64 = 0;
        let mut left = 0;

        for right in 0..nums.len() {
            let val = nums[right];
            let entry = freq.entry(val).or_insert(0);
            count_pairs += *entry as i64;
            *entry += 1;

            while count_pairs >= k as i64 {
                res += (nums.len() - right) as i64;
                let lval = nums[left];
                if let Some(count) = freq.get_mut(&lval) {
                    *count -= 1;
                    count_pairs -= *count as i64;
                }
                left += 1;
            }
        }

        res
    }
}
//sub: https://leetcode.com/problems/count-the-number-of-good-subarrays/submissions/1608090018/?envType=daily-question&envId=2025-04-16
//sol: https://leetcode.com/problems/count-the-number-of-good-subarrays/solutions/6655003/2537-count-the-number-of-good-subarrays-z0rgf/
