//338. Counting Bits
struct Solution;

impl Solution {
    pub fn count_bits(n: i32) -> Vec<i32> {
        (0..=n).map(|i| i.count_ones() as i32).collect()
    }
}

// Example usage:
fn main() {
    let result = Solution::count_bits(5);
    println!("{:?}", result); // Output: [0,1,1,2,1,2]
}
//sub: https://leetcode.com/problems/counting-bits/submissions/1568814494/
//sol: https://leetcode.com/problems/counting-bits/solutions/6519440/338-counting-bits-by-nalindalal2004-2qx2/
