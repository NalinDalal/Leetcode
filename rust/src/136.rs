//136. Single Number
impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut result: i32 = 0;
        for num in nums {
            result ^= num;
        }
        return result;
    }
}
//sub: https://leetcode.com/problems/single-number/submissions/1576385050/
//sol: https://leetcode.com/problems/single-number/solutions/6545649/136-single-number-by-nalindalal2004-5sfc/
