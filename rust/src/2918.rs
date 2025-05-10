//2918. Minimum Equal Sum of Two Arrays After Replacing Zeros

impl Solution {
    pub fn min_sum(nums1: Vec<i32>, nums2: Vec<i32>) -> i64 {
        let mut sum1: i64 = 0;
        let mut sum2: i64 = 0;
        let mut zero1 = 0;
        let mut zero2 = 0;

        for &x in &nums1 {
            sum1 += x as i64;
            if x == 0 {
                sum1 += 1;
                zero1 += 1;
            }
        }

        for &x in &nums2 {
            sum2 += x as i64;
            if x == 0 {
                sum2 += 1;
                zero2 += 1;
            }
        }

        if (zero1 == 0 && sum2 > sum1) || (zero2 == 0 && sum1 > sum2) {
            return -1;
        }

        sum1.max(sum2)
    }
}

//sub: https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/submissions/1629709221/?envType=daily-question&envId=2025-05-10
