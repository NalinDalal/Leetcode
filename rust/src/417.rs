//417. Pacific Atlantic Water Flow
impl Solution {
    pub fn pacific_atlantic(heights: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = heights.len();
        if n == 0 { return vec![]; }
        let m = heights[0].len();

        // Track reachable cells for each ocean
        let mut pacific = vec![vec![false; m]; n];
        let mut atlantic = vec![vec![false; m]; n];

        // Directions: up, down, left, right
        let dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)];

        fn dfs(
            heights: &Vec<Vec<i32>>,
            visited: &mut Vec<Vec<bool>>,
            x: usize,
            y: usize,
            dirs: &[(i32, i32); 4],
        ) {
            visited[x][y] = true;
            let n = heights.len() as i32;
            let m = heights[0].len() as i32;

            for (dx, dy) in dirs.iter() {
                let nx = x as i32 + dx;
                let ny = y as i32 + dy;

                if nx >= 0 && nx < n && ny >= 0 && ny < m {
                    let (nxu, nyu) = (nx as usize, ny as usize);
                    if !visited[nxu][nyu] && heights[nxu][nyu] >= heights[x][y] {
                        dfs(heights, visited, nxu, nyu, dirs);
                    }
                }
            }
        }

        // Pacific Ocean: top and left borders
        for i in 0..n {
            dfs(&heights, &mut pacific, i, 0, &dirs);
        }
        for j in 1..m {
            dfs(&heights, &mut pacific, 0, j, &dirs);
        }

        // Atlantic Ocean: bottom and right borders
        for i in 0..n {
            dfs(&heights, &mut atlantic, i, m - 1, &dirs);
        }
        for j in 0..m - 1 {
            dfs(&heights, &mut atlantic, n - 1, j, &dirs);
        }

        // Cells reachable from both oceans
        let mut ans = Vec::new();
        for i in 0..n {
            for j in 0..m {
                if pacific[i][j] && atlantic[i][j] {
                    ans.push(vec![i as i32, j as i32]);
                }
            }
        }
        ans
    }
}
//sub: https://leetcode.com/problems/pacific-atlantic-water-flow/submissions/1792052240/?envType=daily-question&envId=2025-10-05
//sol: https://leetcode.com/problems/pacific-atlantic-water-flow/solutions/7250636/417-pacific-atlantic-water-flow-by-nalin-rn3z/
