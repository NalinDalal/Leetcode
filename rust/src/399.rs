//399. Evaluate Division
use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn calc_equation(
        equations: Vec<Vec<String>>,
        values: Vec<f64>,
        queries: Vec<Vec<String>>,
    ) -> Vec<f64> {
        let graph = Self::build_graph(equations, values);
        queries
            .iter()
            .map(|q| Self::dfs(&graph, &q[0], &q[1], &mut HashSet::new()))
            .collect()
    }

    fn build_graph(
        equations: Vec<Vec<String>>,
        values: Vec<f64>,
    ) -> HashMap<String, Vec<(String, f64)>> {
        let mut graph = HashMap::new();

        for (i, eq) in equations.iter().enumerate() {
            let (a, b) = (&eq[0], &eq[1]);
            let value = values[i];

            graph
                .entry(a.clone())
                .or_insert(vec![])
                .push((b.clone(), value));
            graph
                .entry(b.clone())
                .or_insert(vec![])
                .push((a.clone(), 1.0 / value));
        }
        graph
    }

    fn dfs(
        graph: &HashMap<String, Vec<(String, f64)>>,
        src: &str,
        dest: &str,
        visited: &mut HashSet<String>,
    ) -> f64 {
        if !graph.contains_key(src) || !graph.contains_key(dest) {
            return -1.0;
        }
        if src == dest {
            return 1.0;
        }

        visited.insert(src.to_string());

        if let Some(neighbors) = graph.get(src) {
            for (neighbor, weight) in neighbors {
                if !visited.contains(neighbor) {
                    let res = Self::dfs(graph, neighbor, dest, visited);
                    if res != -1.0 {
                        return res * weight;
                    }
                }
            }
        }

        -1.0
    }
}

struct Solution;

fn main() {
    let equations = vec![
        vec!["a".to_string(), "b".to_string()],
        vec!["b".to_string(), "c".to_string()],
    ];
    let values = vec![2.0, 3.0];
    let queries = vec![
        vec!["a".to_string(), "c".to_string()],
        vec!["b".to_string(), "a".to_string()],
        vec!["a".to_string(), "e".to_string()],
        vec!["a".to_string(), "a".to_string()],
        vec!["x".to_string(), "x".to_string()],
    ];

    let result = Solution::calc_equation(equations, values, queries);
    println!("{:?}", result); // Expected output: [6.0, 0.5, -1.0, 1.0, -1.0]
}
//sub: https://leetcode.com/problems/evaluate-division/submissions/1586283423/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/evaluate-division/solutions/6579905/399-evaluate-division-by-nalindalal2004-etf2/
