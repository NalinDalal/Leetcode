//137. Single Number II
impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut ones = 0;
        let mut twos = 0;

        for num in nums {
            ones ^= num & !twos;
            twos ^= num & !ones;
        }

        ones
    }
}
//sub: https://leetcode.com/problems/single-number-ii/submissions/1608079793/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/single-number-ii/solutions/6654971/137-single-number-ii-by-nalindalal2004-u5qy/
