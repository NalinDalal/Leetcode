//2845. Count of Interesting Subarrays

use std::collections::HashMap;

impl Solution {
    pub fn count_interesting_subarrays(nums: Vec<i32>, modulo: i32, k: i32) -> i64 {
        let mut count_map = HashMap::new();
        count_map.insert(0, 1); // count[0] = 0 initially

        let mut result = 0i64;
        let mut count = 0;

        for &num in &nums {
            // Increment count if nums[i] % modulo == k
            if num % modulo == k {
                count += 1;
            }

            let key = (count - k).rem_euclid(modulo);
            result += *count_map.get(&key).unwrap_or(&0);

            // Insert/update count % modulo in map
            *count_map.entry(count % modulo).or_insert(0) += 1;
        }

        result
    }
}
//sub: https://leetcode.com/problems/count-of-interesting-subarrays/submissions/1617114810/?envType=daily-question&envId=2025-04-25
