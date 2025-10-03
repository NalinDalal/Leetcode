//407. Trapping Rain Water II
use std::cmp::Reverse;
use std::collections::BinaryHeap;

struct Solution;

impl Solution {
    pub fn trap_rain_water(height_map: Vec<Vec<i32>>) -> i32 {
        let n = height_map.len();
        if n == 0 { return 0; }
        let m = height_map[0].len();
        if m == 0 { return 0; }

        let mut visited = vec![vec![false; m]; n];
        let mut heap = BinaryHeap::new();

        // Push boundary cells into heap
        for i in 0..n {
            visited[i][0] = true;
            visited[i][m - 1] = true;
            heap.push(Reverse((height_map[i][0], i, 0)));
            heap.push(Reverse((height_map[i][m - 1], i, m - 1)));
        }
        for j in 0..m {
            visited[0][j] = true;
            visited[n - 1][j] = true;
            heap.push(Reverse((height_map[0][j], 0, j)));
            heap.push(Reverse((height_map[n - 1][j], n - 1, j)));
        }

        let dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)];
        let mut ans = 0;

        while let Some(Reverse((h, r, c))) = heap.pop() {
            for (dr, dc) in dirs.iter() {
                let nr = r as isize + dr;
                let nc = c as isize + dc;
                if nr >= 0 && nr < n as isize && nc >= 0 && nc < m as isize {
                    let (nr, nc) = (nr as usize, nc as usize);
                    if !visited[nr][nc] {
                        visited[nr][nc] = true;
                        ans += (h - height_map[nr][nc]).max(0);
                        heap.push(Reverse((h.max(height_map[nr][nc]), nr, nc)));
                    }
                }
            }
        }

        ans
    }
}

fn main() {
    let height_map = vec![
        vec![1,4,3,1,3,2],
        vec![3,2,1,3,2,4],
        vec![2,3,3,2,3,1],
    ];
    println!("{}", Solution::trap_rain_water(height_map)); // Output: 4
}
//sub: https://leetcode.com/problems/trapping-rain-water-ii/submissions/1790024056/
//sol: https://leetcode.com/problems/trapping-rain-water-ii/solutions/6301021/407-trapping-rain-water-ii7837-by-nalind-r4dx/
