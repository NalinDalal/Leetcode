//2221. Find Triangular Sum of an Array
impl Solution {
    pub fn triangular_sum(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut c = vec![0; n];
        c[0] = 1;

        // Build binomial coefficients mod 10
        for i in 1..n {
            for j in (1..=i).rev() {
                c[j] = (c[j] + c[j - 1]) % 10;
            }
        }

        let mut result = 0;
        for i in 0..n {
            result = (result + c[i] * nums[i]) % 10;
        }

        result
    }
}
//sub: https://leetcode.com/problems/find-triangular-sum-of-an-array/submissions/1787023231/?envType=daily-question&envId=2025-09-30
//sol: https://leetcode.com/problems/find-triangular-sum-of-an-array/solutions/7235693/2221-find-triangular-sum-of-an-array-by-2cyt7/
