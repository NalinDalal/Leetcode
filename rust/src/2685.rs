//2685. Count the Number of Complete Components
use std::collections::{HashMap, HashSet};
impl Solution {
    pub fn count_complete_components(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let mut adj: HashMap<i32, Vec<i32>> = HashMap::new();
        let mut visited: Vec<bool> = vec![false; n as usize];

        // Build adjacency list
        for edge in &edges {
            adj.entry(edge[0]).or_insert(vec![]).push(edge[1]);
            adj.entry(edge[1]).or_insert(vec![]).push(edge[0]);
        }

        fn dfs(
            node: i32,
            adj: &HashMap<i32, Vec<i32>>,
            visited: &mut Vec<bool>,
            nodes: &mut Vec<i32>,
            edge_count: &mut i32,
        ) {
            visited[node as usize] = true;
            nodes.push(node);
            if let Some(neighbors) = adj.get(&node) {
                for &neighbor in neighbors {
                    *edge_count += 1;
                    if !visited[neighbor as usize] {
                        dfs(neighbor, adj, visited, nodes, edge_count);
                    }
                }
            }
        }

        let mut count = 0;

        for i in 0..n {
            if !visited[i as usize] {
                let mut nodes = vec![];
                let mut edge_count = 0;
                dfs(i, &adj, &mut visited, &mut nodes, &mut edge_count);

                let m = nodes.len() as i32;
                if edge_count / 2 == (m * (m - 1)) / 2 {
                    count += 1;
                }
            }
        }
        count
    }
}
//sub:https://leetcode.com/problems/count-the-number-of-complete-components/submissions/1581853794/?envType=daily-question&envId=2025-03-22
//sol:https://leetcode.com/problems/count-the-number-of-complete-components/solutions/6564867/2685-count-the-number-of-complete-compon-h2tp/
