//2176. Count Equal and Divisible Pairs in an Array

impl Solution {
    pub fn count_pairs(nums: Vec<i32>, k: i32) -> i32 {
        let mut pair: i32 = 0;
        let n = nums.len();

        for i in 0..n - 1 {
            for j in i + 1..n {
                if nums[i] == nums[j] && (i * j) % (k as usize) == 0 {
                    pair += 1;
                }
            }
        }

        pair
    }
}
//sub: https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/submissions/1609186933/?envType=daily-question&envId=2025-04-17
//sol: https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/solutions/6658763/2176-count-equal-and-divisible-pairs-in-m6vth/
