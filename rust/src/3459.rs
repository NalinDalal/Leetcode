//3459. Length of Longest V-Shaped Diagonal Segment
impl Solution {
    pub fn len_of_v_diagonal(grid: Vec<Vec<i32>>) -> i32 {
        let dirs = [[1, 1], [1, -1], [-1, -1], [-1, 1]];
        let m = grid.len();
        let n = grid[0].len();
        let mut memo = vec![vec![vec![vec![-1; 2]; 4]; n]; m];
        
        fn dfs(
            cx: usize, 
            cy: usize, 
            direction: usize, 
            turn: bool, 
            target: i32,
            grid: &Vec<Vec<i32>>,
            memo: &mut Vec<Vec<Vec<Vec<i32>>>>,
            dirs: &[[i32; 2]; 4]
        ) -> i32 {
            let m = grid.len();
            let n = grid[0].len();
            let nx = (cx as i32 + dirs[direction][0]) as usize;
            let ny = (cy as i32 + dirs[direction][1]) as usize;
            /* If it goes beyond the boundary or the next node's value is not the target value, then return */
            if nx >= m || ny >= n || grid[nx][ny] != target {
                return 0;
            }
            
            let turn_int = if turn { 1 } else { 0 };
            if memo[nx][ny][direction][turn_int] != -1 {
                return memo[nx][ny][direction][turn_int];
            }

            /* Continue walking in the original direction. */
            let mut max_step = dfs(nx, ny, direction, turn, 2 - target, grid, memo, dirs);
            if turn {
                /* Clockwise rotate 90 degrees turn */
                max_step = max_step.max(dfs(nx, ny, (direction + 1) % 4, false, 2 - target, grid, memo, dirs));
            }
            memo[nx][ny][direction][turn_int] = max_step + 1;
            max_step + 1
        }

        let mut res = 0;
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 1 {
                    for direction in 0..4 {
                        res = res.max(dfs(i, j, direction, true, 2, &grid, &mut memo, &dirs) + 1);
                    }
                }
            }
        }
        res
    }
}
//sub: https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/submissions/1749759863/
//sol: https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/solutions/7126519/3459-length-of-longest-v-shaped-diagonal-nkd7/
