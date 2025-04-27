//3392. Count Subarrays of Length Three With a Condition
impl Solution {
    pub fn count_subarrays(nums: Vec<i32>) -> i32 {
        let mut count = 0;
        let n = nums.len();

        for i in 0..=n - 3 {
            let first = nums[i];
            let second = nums[i + 1];
            let third = nums[i + 2];
            if second % 2 == 0 && (first + third == second / 2) {
                count += 1;
            }
        }

        count
    }
}
//sub: https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/submissions/1619564542/?envType=daily-question&envId=2025-04-27
