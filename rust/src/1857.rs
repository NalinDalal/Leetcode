//1857. Largest Color Value in a Directed Graph
use std::collections::VecDeque;
impl Solution {
    pub fn largest_path_value(colors: String, edges: Vec<Vec<i32>>) -> i32 {
        let n = colors.len();
        let mut adj = vec![vec![]; n];
        let mut indegree = vec![0; n];

        for edge in edges.iter() {
            let u = edge[0] as usize;
            let v = edge[1] as usize;
            adj[u].push(v);
            indegree[v] += 1;
        }

        let mut q = VecDeque::new();
        for i in 0..n {
            if indegree[i] == 0 {
                q.push_back(i);
            }
        }

        let mut dp = vec![[0; 26]; n];
        let mut seen = 0;
        let mut ans = 0;
        let colors_bytes = colors.as_bytes();

        while let Some(u) = q.pop_front() {
            seen += 1;
            let c = (colors_bytes[u] - b'a') as usize;
            dp[u][c] += 1;
            ans = ans.max(dp[u][c]);

            for &v in adj[u].iter() {
                for k in 0..26 {
                    dp[v][k] = dp[v][k].max(dp[u][k]);
                }
                indegree[v] -= 1;
                if indegree[v] == 0 {
                    q.push_back(v);
                }
            }
        }

        if seen == n {
            ans
        } else {
            -1
        }
    }
}
//sub: https://leetcode.com/problems/largest-color-value-in-a-directed-graph/submissions/1644629493/?envType=daily-question&envId=2025-05-26
