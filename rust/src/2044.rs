//2044. Count Number of Maximum Bitwise-OR Subsets
impl Solution {
    pub fn count_max_or_subsets(nums: Vec<i32>) -> i32 {
        let mut max_or = 0;
        for &num in &nums {
            max_or |= num;
        }

        fn dfs(nums: &Vec<i32>, index: usize, curr_or: i32, max_or: i32, count: &mut i32) {
            if index == nums.len() {
                if curr_or == max_or {
                    *count += 1;
                }
                return;
            }

            // Include nums[index]
            dfs(nums, index + 1, curr_or | nums[index], max_or, count);
            // Exclude nums[index]
            dfs(nums, index + 1, curr_or, max_or, count);
        }

        let mut count = 0;
        dfs(&nums, 0, 0, max_or, &mut count);
        count
    }
}
//sub: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/submissions/1714325762/?envType=daily-question&envId=2025-07-28
//sol: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/solutions/7015088/2044-count-number-of-maximum-bitwise-or-98ei7/
