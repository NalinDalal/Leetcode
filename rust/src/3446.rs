//3446. Sort Matrix by Diagonals
use std::collections::HashMap;

impl Solution {
    pub fn sort_matrix(mut grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = grid.len();
        let n = grid[0].len();
        let mut diag: HashMap<i32, Vec<i32>> = HashMap::new();

        // collect diagonals
        for i in 0..m {
            for j in 0..n {
                diag.entry(i as i32 - j as i32)
                    .or_insert(Vec::new())
                    .push(grid[i][j]);
            }
        }

        // sort conditionally
        for (key, arr) in diag.iter_mut() {
            if *key >= 0 {
                arr.sort_by(|a, b| b.cmp(a)); // non-increasing
            } else {
                arr.sort(); // non-decreasing
            }
        }

        // write back
        for i in 0..m {
            for j in 0..n {
                let key = i as i32 - j as i32;
                let arr = diag.get_mut(&key).unwrap();
                grid[i][j] = arr.remove(0);
            }
        }

        grid
    }
}
//sub: https://leetcode.com/problems/sort-matrix-by-diagonals/?envType=daily-question&envId=2025-08-28
//sol: https://leetcode.com/problems/sort-matrix-by-diagonals/solutions/7130153/3446-sort-matrix-by-diagonals-by-nalinda-mtm3/
