// 75. Sort Colors
impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let (mut low, mut mid, mut high) = (0, 0, nums.len() - 1);

        while mid <= high {
            match nums[mid] {
                0 => {
                    nums.swap(low, mid);
                    low += 1;
                    mid += 1;
                }
                1 => mid += 1,
                2 => {
                    nums.swap(mid, high);
                    if high == 0 {
                        break;
                    } // to avoid underflow
                    high -= 1;
                }
                _ => unreachable!(),
            }
        }
    }
}
//sub: https://leetcode.com/problems/sort-colors/submissions/1636057039/?envType=daily-question&envId=2025-05-17
