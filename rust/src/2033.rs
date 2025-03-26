//2033. Minimum Operations to Make a Uni-Value Grid
use std::collections::HashSet;

impl Solution {
    pub fn min_operations(grid: Vec<Vec<i32>>, x: i32) -> i32 {
        let mut flat: Vec<i32> = grid.iter().flatten().cloned().collect();
        flat.sort();

        // Check if all elements have the same remainder when divided by x
        let remainder = flat[0] % x;
        if flat.iter().any(|&num| num % x != remainder) {
            return -1;
        }

        // Find median as target value
        let median = flat[flat.len() / 2];

        // Calculate minimum operations
        flat.iter().map(|&num| ((num - median).abs()) / x).sum()
    }
}
//sub: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/submissions/1586302030/?envType=daily-question&envId=2025-03-26
//sol: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/solutions/6579946/2033-minimum-operations-to-make-a-uni-va-yvuq/
