//611. Valid Triangle Number
impl Solution {
    pub fn triangle_number(mut nums: Vec<i32>) -> i32 {
         nums.sort();
        let n = nums.len();
        let mut count: i32 = 0;

        for k in (2..n).rev() {
            let mut i = 0;
            let mut j = k - 1;

            while i < j {
                if (nums[i] as i64) + (nums[j] as i64) > (nums[k] as i64) {
                    count += (j - i) as i32;
                    j -= 1;
                } else {
                    i += 1;
                }
            }
        }

        count
    }
}
//sub: https://leetcode.com/problems/valid-triangle-number/submissions/1782942044/?envType=daily-question&envId=2025-09-26
//sol: https://leetcode.com/problems/valid-triangle-number/solutions/7224634/611-valid-triangle-number-by-nalindalal2-1wfq/
