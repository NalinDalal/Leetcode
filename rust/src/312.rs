//312. Burst Balloons
impl Solution {
    pub fn max_coins(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        let n = nums.len();

        // Add boundary 1s
        nums.insert(0, 1);
        nums.push(1);

        let mut dp = vec![vec![0; n + 2]; n + 2];

        for len in 1..=n {
            for left in 1..=n - len + 1 {
                let right = left + len - 1;

                for i in left..=right {
                    let coins = nums[left - 1] * nums[i] * nums[right + 1]
                        + dp[left][i - 1]
                        + dp[i + 1][right];

                    dp[left][right] = dp[left][right].max(coins);
                }
            }
        }

        dp[1][n]
    }
}
//sub: https://leetcode.com/problems/burst-balloons/submissions/1560038440/
//sol: https://leetcode.com/problems/burst-balloons/solutions/6484518/312-burst-balloons-by-nalindalal2004-pzg1/
