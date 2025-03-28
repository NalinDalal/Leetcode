//2503. Maximum Number of Points From Grid Queries

use std::cmp::Reverse;
use std::collections::{BinaryHeap, VecDeque};

impl Solution {
    pub fn max_points(grid: Vec<Vec<i32>>, queries: Vec<i32>) -> Vec<i32> {
        let m = grid.len();
        let n = grid[0].len();
        let mut ans = vec![0; queries.len()];
        let mut sorted_queries: Vec<(i32, usize)> =
            queries.iter().enumerate().map(|(i, &q)| (q, i)).collect();
        sorted_queries.sort_unstable();

        let mut min_heap = BinaryHeap::new();
        let mut visited = vec![vec![false; n]; m];
        let directions = [(0, 1), (1, 0), (0, -1), (-1, 0)];

        min_heap.push(Reverse((grid[0][0], 0, 0)));
        visited[0][0] = true;
        let mut count = 0;

        for (query, index) in sorted_queries {
            while let Some(Reverse((value, x, y))) = min_heap.peek() {
                if *value >= query {
                    break;
                }
                let (value, x, y) = min_heap.pop().unwrap().0; // Extract and unwrap values
                count += 1;

                for &(dx, dy) in &directions {
                    let nx = x as isize + dx;
                    let ny = y as isize + dy;

                    if nx >= 0 && ny >= 0 && nx < m as isize && ny < n as isize {
                        let nx = nx as usize;
                        let ny = ny as usize;
                        if !visited[nx][ny] {
                            visited[nx][ny] = true;
                            min_heap.push(Reverse((grid[nx][ny], nx, ny)));
                        }
                    }
                }
            }
            ans[index] = count;
        }
        ans
    }
}
//sub: https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/submissions/1588893097/?envType=daily-question&envId=2025-03-28
//sol: https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/solutions/6588563/2503-maximum-number-of-points-from-grid-804wd/
