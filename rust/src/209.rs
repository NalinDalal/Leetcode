//209. Minimum Size Subarray Sum
impl Solution {
    pub fn min_sub_array_len(target: i32, nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut min_len = i32::MAX;
        let mut left = 0;
        let mut sum = 0;

        for right in 0..n {
            sum += nums[right];

            while sum >= target {
                min_len = min_len.min((right - left + 1) as i32);
                sum -= nums[left];
                left += 1;
            }
        }

        if min_len == i32::MAX {
            0
        } else {
            min_len
        }
    }
}

//sub: https://leetcode.com/problems/minimum-size-subarray-sum/submissions/1604128890/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/minimum-size-subarray-sum/solutions/6641473/209-minimum-size-subarray-sum-by-nalinda-nf30/
