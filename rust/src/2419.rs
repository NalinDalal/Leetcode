
//2419. Longest Subarray With Maximum Bitwise AND
impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let max_val = *nums.iter().max().unwrap();
        let mut longest = 0;
        let mut current = 0;

        for &num in &nums {
            if num == max_val {
                current += 1;
                longest = longest.max(current);
            } else {
                current = 0;
            }
        }

        longest
    }
}
//sub: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/submissions/1716479587/
//sol: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/solutions/7022002/2419-longest-subarray-with-maximum-bitwi-6z4b/
