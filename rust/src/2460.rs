//2460. Apply Operations to an Array

impl Solution {
    pub fn apply_operations(mut nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();

        // Apply operations as described
        for i in 0..n - 1 {
            if nums[i] == nums[i + 1] {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        // Move all zeros to the end using two-pointer approach
        let mut non_zero_index = 0;
        for i in 0..n {
            if nums[i] != 0 {
                nums.swap(i, non_zero_index);
                non_zero_index += 1;
            }
        }

        nums
    }
}
//sub: https://leetcode.com/problems/apply-operations-to-an-array/submissions/1558700083/?envType=daily-question&envId=2025-03-01
//sol: https://leetcode.com/problems/apply-operations-to-an-array/solutions/6479258/2460-apply-operations-to-an-array-by-nal-kctz/
