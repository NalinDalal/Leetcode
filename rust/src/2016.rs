//2016. Maximum Difference Between Increasing Elements
impl Solution {
    pub fn maximum_difference(nums: Vec<i32>) -> i32 {
        let mut max_ans = -1;
        let n = nums.len();
        for i in 0..n {
            for j in i + 1..n {
                if nums[i] < nums[j] {
                    max_ans = max_ans.max(nums[j] - nums[i]);
                }
            }
        }
        max_ans
    }
}

//sub: https://leetcode.com/problems/maximum-difference-between-increasing-elements/submissions/1665434770/?envType=daily-question&envId=2025-06-16
//sol: https://leetcode.com/problems/maximum-difference-between-increasing-elements/solutions/6848067/2016-maximum-difference-between-increasi-ls3w/
