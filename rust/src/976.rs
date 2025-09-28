//976. Largest Perimeter Triangle
impl Solution {
    pub fn largest_perimeter(nums: Vec<i32>) -> i32 {
        nums.sort_by(|a, b| b.cmp(a)); // sort descending
        let n = nums.len();

        for i in 0..n-2 {
            let a = nums[i];
            let b = nums[i + 1];
            let c = nums[i + 2];
            if a < b + c {
                return a + b + c;
            }
        }
        0
    }
}
//sub: https://leetcode.com/problems/largest-perimeter-triangle/submissions/1785398588/?envType=daily-question&envId=2025-09-28
//sol: https://leetcode.com/problems/largest-perimeter-triangle/solutions/7231449/976-largest-perimeter-triangle-by-nalind-9b47/
