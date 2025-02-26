impl Solution {
    pub fn max_absolute_sum(nums: Vec<i32>) -> i32 {
        let mut sum: i32 = 0;
        let mut minSum: i32 = 0;
        let mut maxSum: i32 = 0;
        for num in nums {
            sum += num;
            if (sum > maxSum) {
                maxSum = sum;
            }
            if (sum < minSum) {
                minSum = sum;
            }
        }
        let ans: i32 = maxSum - minSum;
        return ans.abs();
    }
}
