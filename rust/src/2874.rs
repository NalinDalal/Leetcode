//2874. Maximum Value of an Ordered Triplet II
impl Solution {
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let n = nums.len();
        if n < 3 {
            return 0;
        }

        let mut max_before = vec![0; n];
        let mut max_after = vec![0; n];

        // Compute max_before[j]: max value before index j
        max_before[0] = nums[0];
        for j in 1..n {
            max_before[j] = max_before[j - 1].max(nums[j - 1]);
        }

        // Compute max_after[j]: max value after index j
        max_after[n - 1] = nums[n - 1];
        for j in (0..n - 1).rev() {
            max_after[j] = max_after[j + 1].max(nums[j + 1]);
        }

        let mut max_value = 0i64;

        // Iterate over `j`
        for j in 1..n - 1 {
            let left = max_before[j] as i64;
            let mid = nums[j] as i64;
            let right = max_after[j] as i64;

            let value = (left - mid) * right;
            max_value = max_value.max(value);
        }

        max_value
    }
}
//sub: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/submissions/1595490069/?envType=daily-question&envId=2025-04-03
//sol: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/solutions/6610983/2874-maximum-value-of-an-ordered-triplet-xkqh/
