//3375. Minimum Operations to Make Array Values Equal to K

use std::collections::HashSet;
impl Solution {
    pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
        let mut st = HashSet::new();
        for x in nums {
            if x < k {
                return -1;
            } else if x > k {
                st.insert(x);
            }
        }
        st.len() as i32
    }
}
//sub: https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/submissions/1601206965/?envType=daily-question&envId=2025-04-09
