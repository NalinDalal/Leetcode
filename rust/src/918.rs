//918. Maximum Sum Circular Subarray
impl Solution {
    pub fn max_subarray_sum_circular(nums: Vec<i32>) -> i32 {
        let mut total = 0;
        let mut max_sum = nums[0];
        let mut cur_max = 0;
        let mut min_sum = nums[0];
        let mut cur_min = 0;

        for &num in &nums {
            cur_max = i32::max(num, cur_max + num);
            max_sum = i32::max(max_sum, cur_max);

            cur_min = i32::min(num, cur_min + num);
            min_sum = i32::min(min_sum, cur_min);

            total += num;
        }

        // If all numbers are negative, max_sum is the best we can do
        if max_sum < 0 {
            max_sum
        } else {
            i32::max(max_sum, total - min_sum)
        }
    }
}
//sub: https://leetcode.com/problems/maximum-sum-circular-subarray/submissions/1599071922/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/maximum-sum-circular-subarray/solutions/6623843/918-maximum-sum-circular-subarray-by-nal-009f/
