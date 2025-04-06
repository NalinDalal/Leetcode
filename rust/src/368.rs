//368. Largest Divisible Subset

impl Solution {
    pub fn largest_divisible_subset(mut nums: Vec<i32>) -> Vec<i32> {
        if nums.is_empty() {
            return vec![];
        }

        nums.sort();
        let n = nums.len();
        let mut dp = vec![1; n];
        let mut prev = vec![-1; n];
        let mut max_idx = 0;

        for i in 1..n {
            for j in 0..i {
                if nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i] {
                    dp[i] = dp[j] + 1;
                    prev[i] = j as i32;
                }
            }
            if dp[i] > dp[max_idx] {
                max_idx = i;
            }
        }

        let mut result = vec![];
        let mut i = max_idx as i32;
        while i >= 0 {
            result.push(nums[i as usize]);
            i = prev[i as usize];
        }

        result.reverse();
        result
    }
}
//sub: https://leetcode.com/problems/largest-divisible-subset/submissions/1598125911/?envType=daily-question&envId=2025-04-06
//sol: https://leetcode.com/problems/largest-divisible-subset/solutions/6620526/368-largest-divisible-subset-by-nalindal-m15d/
