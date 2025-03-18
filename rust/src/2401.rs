//2401. Longest Nice Subarray
impl Solution {
    pub fn longest_nice_subarray(nums: Vec<i32>) -> i32 {
        let (mut left, mut bitmask, mut max_len) = (0, 0, 0);

        for right in 0..nums.len() {
            while (bitmask & nums[right]) != 0 {
                bitmask ^= nums[left]; // Remove leftmost number from bitmask
                left += 1; // Shrink window
            }

            bitmask |= nums[right]; // Add current number to bitmask
            max_len = max_len.max(right as i32 - left as i32 + 1); // Update max length
        }

        max_len
    }
}

//sub: https://leetcode.com/problems/longest-nice-subarray/submissions/1577519372/?envType=daily-question&envId=2025-03-18
//sol: https://leetcode.com/problems/longest-nice-subarray/solutions/6549906/2401-longest-nice-subarray-by-nalindalal-39mu/
