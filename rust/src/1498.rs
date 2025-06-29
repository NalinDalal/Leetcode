//1498. Number of Subsequences That Satisfy the Given Sum Condition
impl Solution {
    pub fn num_subseq(mut nums: Vec<i32>, target: i32) -> i32 {
        const MOD: i32 = 1_000_000_007;
        nums.sort();
        let n = nums.len();

        // Precompute powers of 2
        let mut power = vec![1; n];
        for i in 1..n {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        let (mut left, mut right) = (0, n - 1);
        let mut res = 0;

        while left <= right {
            if nums[left] + nums[right] <= target {
                res = (res + power[right - left]) % MOD;
                left += 1;
            } else {
                if right == 0 {
                    break;
                }
                right -= 1;
            }
        }

        res
    }
}
//sub: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/submissions/1680033372/?envType=daily-question&envId=2025-06-29
//sol: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/solutions/6897849/1498-number-of-subsequences-that-satisfy-mrap/
