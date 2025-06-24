//2200. Find All K-Distant Indices in an Array
use std::collections::BTreeSet;

impl Solution {
    pub fn find_k_distant_indices(nums: Vec<i32>, key: i32, k: i32) -> Vec<i32> {
        let mut result = BTreeSet::new();

        for (i, &num) in nums.iter().enumerate() {
            if num == key {
                let start = i.saturating_sub(k as usize);
                let end = usize::min(i + k as usize, nums.len() - 1);
                for j in start..=end {
                    result.insert(j as i32);
                }
            }
        }

        result.into_iter().collect()
    }
}
//sub: https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/submissions/1674989099/
//sol: https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/solutions/6880814/2200-find-all-k-distant-indices-in-an-ar-7gmf/
