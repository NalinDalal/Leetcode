//2962. Count Subarrays Where Max Element Appears at Least K Times
impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, k: i32) -> i64 {
        let max_element = *nums.iter().max().unwrap();
        let mut ans = 0i64;
        let mut start = 0usize;
        let mut max_elements_in_window = 0;

        for end in 0..nums.len() {
            if nums[end] == max_element {
                max_elements_in_window += 1;
            }
            while max_elements_in_window == k {
                if nums[start] == max_element {
                    max_elements_in_window -= 1;
                }
                start += 1;
            }
            ans += start as i64;
        }
        ans
    }
}
//sub: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/submissions/1620704328/?envType=daily-question&envId=2025-04-29
