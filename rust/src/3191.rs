//3191. Minimum Operations to Make Binary Array Elements Equal to One I
impl Solution {
    pub fn min_operations(mut nums: Vec<i32>) -> i32 {
        let mut flips = 0;
        let n = nums.len();

        for i in 0..=n.saturating_sub(3) {
            if nums[i] == 0 {
                // Flip current element and next two
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                flips += 1;
            }
        }

        // Check last two elements
        for i in n.saturating_sub(2)..n {
            if i < n && nums[i] == 0 {
                return -1;
            }
        }

        flips
    }
}
//su: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/?envType=daily-question&envId=2025-03-19
//sol: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/solutions/6554078/3191-minimum-operations-to-make-binary-a-ql6r/
