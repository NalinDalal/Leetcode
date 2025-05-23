//3068. Find the Maximum Sum of Node Values
impl Solution {
    pub fn maximum_value_sum(nums: Vec<i32>, k: i32, edges: Vec<Vec<i32>>) -> i64 {
        fn dfs(
            index: usize,
            is_even: usize,
            nums: &Vec<i32>,
            k: i32,
            memo: &mut Vec<[i64; 2]>,
        ) -> i64 {
            if index == nums.len() {
                return if is_even == 1 { 0 } else { i64::MIN / 2 };
            }

            if memo[index][is_even] != -1 {
                return memo[index][is_even];
            }

            let no_xor = nums[index] as i64 + dfs(index + 1, is_even, nums, k, memo);
            let xor_done = (nums[index] ^ k) as i64 + dfs(index + 1, 1 - is_even, nums, k, memo);

            memo[index][is_even] = no_xor.max(xor_done);
            memo[index][is_even]
        }

        let n = nums.len();
        let mut memo = vec![[-1; 2]; n];
        dfs(0, 1, &nums, k, &mut memo)
    }
}

//sub: https://leetcode.com/problems/find-the-maximum-sum-of-node-values/submissions/1641977980/?envType=daily-question&envId=2025-05-23
//sol: https://leetcode.com/problems/find-the-maximum-sum-of-node-values/solutions/6772344/3068-find-the-maximum-sum-of-node-values-34kr/
