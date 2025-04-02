//2873. Maximum Value of an Ordered Triplet I
impl Solution {
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let n = nums.len();
        if n < 3 {
            return 0;
        }

        let mut max_i = nums[0]; // Track max nums[i]
        let mut max_value: i64 = 0; // Store maximum triplet value safely in i64

        let mut best_diff = vec![0; n]; // Store best (nums[i] - nums[j]) values

        // Compute best (nums[i] - nums[j]) seen so far
        for j in 1..n - 1 {
            best_diff[j] = best_diff[j - 1].max(max_i - nums[j]);
            max_i = max_i.max(nums[j]); // Update max_i
        }

        // Compute maximum triplet value
        for k in 2..n {
            max_value = max_value.max(best_diff[k - 1] as i64 * nums[k] as i64);
        }

        max_value
    }
}
//sub: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/submissions/1594083198/?envType=daily-question&envId=2025-04-02
//sol: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/solutions/6606327/2873-maximum-value-of-an-ordered-triplet-bw88/
