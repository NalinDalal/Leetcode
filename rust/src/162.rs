//162. Find Peak Element

impl Solution {
    pub fn find_peak_element(nums: Vec<i32>) -> i32 {
        if nums.is_empty() {
            return -1; // Return -1 for an empty array
        }

        let mut max_index = 0;
        for i in 1..nums.len() {
            if nums[i] > nums[max_index] {
                max_index = i;
            }
        }

        max_index as i32 // Convert usize to i32 since return type is i32
    }
}
//sub:https://leetcode.com/problems/find-peak-element/submissions/1589635922/?envType=study-plan-v2&envId=top-interview-150
//sol:https://leetcode.com/problems/find-peak-element/solutions/6591239/162-find-peak-element-by-nalindalal2004-mcpc/
