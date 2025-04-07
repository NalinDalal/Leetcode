//416. Partition Sum
impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
        let total_sum: i32 = nums.iter().sum();

        // If the total sum is odd, we can't split it into two equal subsets
        if total_sum % 2 != 0 {
            return false;
        }

        let target = (total_sum / 2) as usize;
        let mut dp = vec![false; target + 1];
        dp[0] = true; // Base case: subset sum of 0 is always possible

        for &num in &nums {
            let num = num as usize;
            for j in (num..=target).rev() {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        dp[target]
    }
}
//sub: https://leetcode.com/problems/partition-equal-subset-sum/submissions/1599066626/?envType=daily-question&envId=2025-04-07
//sol: https://leetcode.com/problems/partition-equal-subset-sum/solutions/6449661/416-partition-equal-subset-sum-by-nalind-p2tv/
