//3373. Maximize the Number of Target Nodes After Connecting Trees II
use std::collections::VecDeque;
impl Solution {
    pub fn max_target_nodes(edges1: Vec<Vec<i32>>, edges2: Vec<Vec<i32>>) -> Vec<i32> {
        fn build_graph(edges: &[Vec<i32>], size: usize) -> Vec<Vec<usize>> {
            let mut graph = vec![vec![]; size];
            for edge in edges {
                let u = edge[0] as usize;
                let v = edge[1] as usize;
                graph[u].push(v);
                graph[v].push(u);
            }
            graph
        }

        fn dfs(
            node: usize,
            parent: isize,
            depth: usize,
            graph: &[Vec<usize>],
            parity: &mut Vec<usize>,
        ) -> (i32, i32) {
            parity[node] = depth % 2;
            let mut even = if depth % 2 == 0 { 1 } else { 0 };
            let mut odd = if depth % 2 == 1 { 1 } else { 0 };

            for &neighbor in &graph[node] {
                if neighbor as isize != parent {
                    let (e, o) = dfs(neighbor, node as isize, depth + 1, graph, parity);
                    even += e;
                    odd += o;
                }
            }
            (even, odd)
        }

        let n = edges1.len() + 1;
        let m = edges2.len() + 1;

        let graph1 = build_graph(&edges1, n);
        let graph2 = build_graph(&edges2, m);

        let mut parity1 = vec![0; n];
        let mut parity2 = vec![0; m];

        let (even1, odd1) = dfs(0, -1, 0, &graph1, &mut parity1);
        let (even2, odd2) = dfs(0, -1, 0, &graph2, &mut parity2);

        let mut answer = vec![0; n];
        for i in 0..n {
            answer[i] = if parity1[i] == 0 {
                even1 + even2.max(odd2)
            } else {
                odd1 + even2.max(odd2)
            };
        }

        answer
    }
}
//sub: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/submissions/1647533427/?envType=daily-question&envId=2025-05-29
//sol: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/solutions/6791228/3373-maximize-the-number-of-target-nodes-a3ji/
