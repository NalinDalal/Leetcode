//3349. Adjacent Increasing Subarrays Detection I
impl Solution {
    pub fn has_increasing_subarrays(nums: Vec<i32>, k: i32) -> bool {
        let n = nums.len();
        if n < 2 * k as usize {
            return false;
        }

        let mut current_increasing = 1;
        let mut previous_increasing = 0;

        for i in 1..n {
            // Check if two adjacent increasing subarrays exist
            if Solution::found_two_adjacent(current_increasing, previous_increasing, k) {
                return true;
            }

            if nums[i - 1] >= nums[i] {
                previous_increasing = current_increasing;
                current_increasing = 1;
            } else {
                current_increasing += 1;
            }
        }

        // Final check at the end of the array
        Solution::found_two_adjacent(current_increasing, previous_increasing, k)
    }

    fn found_two_adjacent(current: usize, previous: usize, k: i32) -> bool {
        let k = k as usize;
        current >= 2 * k || (current >= k && previous >= k)
    }
}

//sub: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/submissions/1801150428/?envType=daily-question&envId=2025-10-14
//sol: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/solutions/7274080/3349-adjacent-increasing-subarrays-detec-4f8y/
