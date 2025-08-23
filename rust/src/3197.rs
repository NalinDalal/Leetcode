//3197. Find the Minimum Area to Cover All Ones II
impl Solution {
    pub fn minimum_sum(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let m = grid[0].len();
        let inf = 1_000_000_000;

        let rect_area = |r1: usize, r2: usize, c1: usize, c2: usize, g: &Vec<Vec<i32>>| -> i32 {
            let mut minr = n as i32;
            let mut maxr = -1;
            let mut minc = m as i32;
            let mut maxc = -1;
            for i in r1..=r2 {
                for j in c1..=c2 {
                    if g[i][j] == 1 {
                        minr = minr.min(i as i32);
                        maxr = maxr.max(i as i32);
                        minc = minc.min(j as i32);
                        maxc = maxc.max(j as i32);
                    }
                }
            }
            if maxr == -1 { return inf; }
            (maxr - minr + 1) * (maxc - minc + 1)
        };

        let mut ans = inf;

        // Case 1: 3 vertical stripes
        for c1 in 0..m-2 {
            for c2 in c1+1..m-1 {
                let a1 = rect_area(0, n-1, 0, c1, &grid);
                let a2 = rect_area(0, n-1, c1+1, c2, &grid);
                let a3 = rect_area(0, n-1, c2+1, m-1, &grid);
                if a1 < inf && a2 < inf && a3 < inf {
                    ans = ans.min(a1 + a2 + a3);
                }
            }
        }

        // Case 2: 3 horizontal stripes
        for r1 in 0..n-2 {
            for r2 in r1+1..n-1 {
                let a1 = rect_area(0, r1, 0, m-1, &grid);
                let a2 = rect_area(r1+1, r2, 0, m-1, &grid);
                let a3 = rect_area(r2+1, n-1, 0, m-1, &grid);
                if a1 < inf && a2 < inf && a3 < inf {
                    ans = ans.min(a1 + a2 + a3);
                }
            }
        }

        // Case 3 & 4: vertical cut
        for c in 0..m-1 {
            // left rectangle, split right
            let left = rect_area(0, n-1, 0, c, &grid);
            if left < inf {
                for r in 0..n-1 {
                    let a2 = rect_area(0, r, c+1, m-1, &grid);
                    let a3 = rect_area(r+1, n-1, c+1, m-1, &grid);
                    if a2 < inf && a3 < inf {
                        ans = ans.min(left + a2 + a3);
                    }
                }
            }
            // right rectangle, split left
            let right = rect_area(0, n-1, c+1, m-1, &grid);
            if right < inf {
                for r in 0..n-1 {
                    let a2 = rect_area(0, r, 0, c, &grid);
                    let a3 = rect_area(r+1, n-1, 0, c, &grid);
                    if a2 < inf && a3 < inf {
                        ans = ans.min(right + a2 + a3);
                    }
                }
            }
        }

        // Case 5 & 6: horizontal cut
        for r in 0..n-1 {
            // top rect, split bottom
            let top = rect_area(0, r, 0, m-1, &grid);
            if top < inf {
                for c in 0..m-1 {
                    let a2 = rect_area(r+1, n-1, 0, c, &grid);
                    let a3 = rect_area(r+1, n-1, c+1, m-1, &grid);
                    if a2 < inf && a3 < inf {
                        ans = ans.min(top + a2 + a3);
                    }
                }
            }
            // bottom rect, split top
            let bottom = rect_area(r+1, n-1, 0, m-1, &grid);
            if bottom < inf {
                for c in 0..m-1 {
                    let a2 = rect_area(0, r, 0, c, &grid);
                    let a3 = rect_area(0, r, c+1, m-1, &grid);
                    if a2 < inf && a3 < inf {
                        ans = ans.min(bottom + a2 + a3);
                    }
                }
            }
        }

        ans
    }
}
//sub: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/submissions/1744908511/?envType=daily-question&envId=2025-08-23
//sol: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/solutions/7111782/3197-find-the-minimum-area-to-cover-all-3gb6n/
