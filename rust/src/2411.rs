//2411. Smallest Subarrays With Maximum Bitwise OR
impl Solution {
    pub fn smallest_subarrays(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut answer = vec![0; n];
        let mut last_seen = vec![-1; 32]; // last seen index for each bit

        for i in (0..n).rev() {
            for b in 0..32 {
                if (nums[i] & (1 << b)) != 0 {
                    last_seen[b] = i as i32;
                }
            }

            let mut max_index = i as i32;
            for &idx in &last_seen {
                if idx != -1 {
                    max_index = max_index.max(idx);
                }
            }

            answer[i] = (max_index - i as i32 + 1) as i32;
        }

        answer
    }
}
//sub: https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/submissions/1715651009/
//sol: https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/solutions/7019344/2411-smallest-subarrays-with-maximum-bit-p9k4/
