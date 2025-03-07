//2965. Find Missing and Repeated Values
use std::collections::HashMap;

impl Solution {
    pub fn find_missing_and_repeated_values(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let n = grid.len();
        let max_num = (n * n) as i32;
        let mut count = HashMap::new();

        // Count occurrences of each number
        for row in &grid {
            for &num in row {
                *count.entry(num).or_insert(0) += 1;
            }
        }

        let (mut repeated, mut missing) = (-1, -1);

        // Find repeated and missing numbers
        for i in 1..=max_num {
            match count.get(&i) {
                Some(&2) => repeated = i,
                None => missing = i,
                _ => {}
            }
        }

        vec![repeated, missing]
    }
}
//sub: https://leetcode.com/problems/find-missing-and-repeated-values/submissions/1564597561/
//sol:
