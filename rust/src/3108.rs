//3108. Minimum Cost Walk in Weighted Graph
struct DSU {
    parent: Vec<i32>,
    depth: Vec<i32>,
}

impl DSU {
    fn new(n: usize) -> Self {
        Self {
            parent: vec![-1; n],
            depth: vec![0; n],
        }
    }

    fn find(&mut self, node: usize) -> usize {
        if self.parent[node] == -1 {
            return node;
        }
        self.parent[node] = self.find(self.parent[node] as usize) as i32;
        self.parent[node] as usize
    }

    fn union(&mut self, node1: usize, node2: usize) {
        let root1 = self.find(node1);
        let root2 = self.find(node2);

        if root1 == root2 {
            return;
        }

        if self.depth[root1] < self.depth[root2] {
            self.parent[root1] = root2 as i32;
        } else if self.depth[root1] > self.depth[root2] {
            self.parent[root2] = root1 as i32;
        } else {
            self.parent[root2] = root1 as i32;
            self.depth[root1] += 1;
        }
    }
}

impl Solution {
    pub fn minimum_cost(n: i32, edges: Vec<Vec<i32>>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut dsu = DSU::new(n as usize);
        let mut component_cost = vec![u32::MAX; n as usize]; // Equivalent to -1 in unsigned

        // Build connected components
        for edge in &edges {
            dsu.union(edge[0] as usize, edge[1] as usize);
        }

        // Compute the AND-weight for each component
        for edge in &edges {
            let root = dsu.find(edge[0] as usize);
            component_cost[root] &= edge[2] as u32;
        }

        // Answer queries
        queries
            .iter()
            .map(|query| {
                let (s, t) = (query[0] as usize, query[1] as usize);
                if dsu.find(s) == dsu.find(t) {
                    component_cost[dsu.find(s)] as i32
                } else {
                    -1
                }
            })
            .collect()
    }
}
//sub: https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/submissions/1579684661/?envType=daily-question&envId=2025-03-20
//sol: https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/solutions/6557565/3108-minimum-cost-walk-in-weighted-graph-gbwo/
