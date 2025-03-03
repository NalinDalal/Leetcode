//2161. Partition Array According to Given Pivot
impl Solution {
    pub fn pivot_array(nums: Vec<i32>, pivot: i32) -> Vec<i32> {
        let mut less = Vec::new();
        let mut equal = Vec::new();
        let mut greater = Vec::new();

        for &num in &nums {
            if num < pivot {
                less.push(num);
            } else if num == pivot {
                equal.push(num);
            } else {
                greater.push(num);
            }
        }

        less.extend(equal);
        less.extend(greater);

        less
    }
}
//sub: https://leetcode.com/problems/partition-array-according-to-given-pivot/submissions/1561014335/?envType=daily-question&envId=2025-03-03
//sol: https://leetcode.com/problems/partition-array-according-to-given-pivot/solutions/6488526/2161-partition-array-according-to-given-em6zr/
