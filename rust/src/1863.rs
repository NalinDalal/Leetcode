//1863. Sum of All Subset XOR Totals

pub struct Solution;

impl Solution {
    pub fn subset_xor_sum(nums: Vec<i32>) -> i32 {
        fn dfs(nums: &Vec<i32>, index: usize, current_xor: i32) -> i32 {
            if index == nums.len() {
                return current_xor;
            }
            let with = dfs(nums, index + 1, current_xor ^ nums[index]);
            let without = dfs(nums, index + 1, current_xor);
            with + without
        }

        dfs(&nums, 0, 0)
    }
}
//sub: https://leetcode.com/problems/sum-of-all-subset-xor-totals/submissions/1597154504/?envType=daily-question&envId=2025-04-05
//sol: https://leetcode.com/problems/sum-of-all-subset-xor-totals/solutions/6617248/1863-sum-of-all-subset-xor-totals-by-nal-jlgc/
