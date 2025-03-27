//2780. Minimum Index of a Valid Split
impl Solution {
    pub fn minimum_index(nums: Vec<i32>) -> i32 {
        let n = nums.len() as i32;

        // Step 1: Find the dominant element using Boyer-Moore Voting Algorithm
        let (mut candidate, mut count) = (-1, 0);
        for &num in &nums {
            if count == 0 {
                candidate = num;
            }
            count += if num == candidate { 1 } else { -1 };
        }

        // Step 2: Validate if candidate is actually dominant
        let total_count = nums.iter().filter(|&&x| x == candidate).count() as i32;
        if total_count * 2 <= n {
            return -1; // No dominant element
        }

        // Step 3: Find the minimum index where both halves share the dominant element
        let (mut prefix_count, mut suffix_count) = (0, total_count);
        for i in 0..(n - 1) as usize {
            if nums[i] == candidate {
                prefix_count += 1;
                suffix_count -= 1;
            }

            if prefix_count * 2 > (i as i32 + 1) && suffix_count * 2 > (n - i as i32 - 1) {
                return i as i32;
            }
        }

        -1
    }
}
//sub: https://leetcode.com/problems/minimum-index-of-a-valid-split/submissions/1587734846/?envType=daily-question&envId=2025-03-27
//sol: https://leetcode.com/problems/minimum-index-of-a-valid-split/solutions/6584682/2780-minimum-index-of-a-valid-split-by-n-01rt/
