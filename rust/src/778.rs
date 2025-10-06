//778. Swim in Rising Water
use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
    pub fn swim_in_water(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let directions = [(0, 1), (1, 0), (0, -1), (-1, 0)];

        let mut visited = vec![vec![false; n]; n];
        let mut heap = BinaryHeap::new();

        // Min-heap by pushing Reverse(elevation)
        heap.push((Reverse(grid[0][0]), 0, 0));
        visited[0][0] = true;

        let mut ans = 0;

        while let Some((Reverse(elevation), x, y)) = heap.pop() {
            ans = ans.max(elevation);
            if x == n - 1 && y == n - 1 {
                return ans;
            }

            for (dx, dy) in directions {
                let nx = x as isize + dx;
                let ny = y as isize + dy;
                if nx >= 0 && ny >= 0 && nx < n as isize && ny < n as isize {
                    let (nx, ny) = (nx as usize, ny as usize);
                    if !visited[nx][ny] {
                        visited[nx][ny] = true;
                        heap.push((Reverse(grid[nx][ny]), nx, ny));
                    }
                }
            }
        }

        -1
    }
}

//sub: https://leetcode.com/problems/swim-in-rising-water/submissions/1793085699/?envType=daily-question&envId=2025-10-06
//sol: https://leetcode.com/problems/swim-in-rising-water/solutions/6431445/778-swim-in-rising-water/?envType=daily-question&envId=2025-10-06
