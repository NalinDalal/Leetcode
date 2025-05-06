//1920. Build Array from Permutation

impl Solution {
    pub fn build_array(nums: Vec<i32>) -> Vec<i32> {
        let mut ans = vec![0; nums.len()];
        for i in 0..nums.len() {
            ans[i] = nums[nums[i] as usize];
        }
        ans
    }
}

//sub: https://leetcode.com/problems/build-array-from-permutation/submissions/1626598260/?envType=daily-question&envId=2025-05-06
