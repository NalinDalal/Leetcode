//2359. Find Closest Node to Given Two Nodes

impl Solution {
    pub fn closest_meeting_node(edges: Vec<i32>, node1: i32, node2: i32) -> i32 {
        fn get_distances(edges: &Vec<i32>, start: usize) -> Vec<i32> {
            let n = edges.len();
            let mut dist = vec![-1; n];
            let mut current = Some(start);
            let mut d = 0;

            while let Some(node) = current {
                if dist[node] != -1 {
                    break;
                }
                dist[node] = d;
                d += 1;

                let next = edges[node];
                current = if next == -1 {
                    None
                } else {
                    Some(next as usize)
                };
            }

            dist
        }

        let dist1 = get_distances(&edges, node1 as usize);
        let dist2 = get_distances(&edges, node2 as usize);
        let mut min_dist = i32::MAX;
        let mut result = -1;

        for i in 0..edges.len() {
            if dist1[i] != -1 && dist2[i] != -1 {
                let max_dist = dist1[i].max(dist2[i]);
                if max_dist < min_dist {
                    min_dist = max_dist;
                    result = i as i32;
                }
            }
        }

        result
    }
}

//sub: https://leetcode.com/problems/find-closest-node-to-given-two-nodes/submissions/1648551520/
//sol: https://leetcode.com/problems/find-closest-node-to-given-two-nodes/solutions/6794562/2359-find-closest-node-to-given-two-node-pxgb/
