//3423. Maximum Difference Between Adjacent Elements in a Circular Array
impl Solution {
    pub fn max_adjacent_distance(nums: Vec<i32>) -> i32 {
        if nums.is_empty() {
            return 0; // or handle according to the problem's constraint
        }

        let mut ans: i32 = (nums[0] - nums[nums.len() - 1]).abs();

        for i in 0..nums.len() - 1 {
            ans = ans.max((nums[i] - nums[i + 1]).abs());
        }

        ans
    }
}

//sub: https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/submissions/1661513076/?envType=daily-question&envId=2025-06-12
//sol: https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/solutions/6834794/3423-maximum-difference-between-adjacent-tvke/
