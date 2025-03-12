//268. Missing Number
impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let n = nums.len() as i32;
        let expected_sum = (n * (n + 1)) / 2;
        let actual_sum: i32 = nums.iter().sum();

        expected_sum - actual_sum
    }
}
//sub: https://leetcode.com/problems/missing-number/submissions/1570881819/
//sol: https://leetcode.com/problems/missing-number/solutions/6526404/268-missing-number-by-nalindalal2004-hpbp/
