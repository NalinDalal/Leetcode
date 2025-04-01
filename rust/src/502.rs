//502. IPO
use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
    pub fn find_maximized_capital(k: i32, w: i32, profits: Vec<i32>, capital: Vec<i32>) -> i32 {
        let mut projects: Vec<(i32, i32)> = capital.into_iter().zip(profits.into_iter()).collect();

        // Step 1: Sort projects by required capital (ascending order)
        projects.sort_by_key(|&(c, _)| c);

        let mut max_heap = BinaryHeap::new(); // Max-Heap for profits
        let mut i = 0;
        let mut w = w;
        let n = projects.len();

        // Step 2: Pick up to k projects
        for _ in 0..k {
            // Add all projects that can be started to the max-heap
            while i < n && projects[i].0 <= w {
                max_heap.push(projects[i].1);
                i += 1;
            }

            // If no projects are available, break early
            if let Some(max_profit) = max_heap.pop() {
                w += max_profit;
            } else {
                break;
            }
        }

        w
    }
}
//sub: https://leetcode.com/problems/ipo/submissions/1592770930/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/ipo/solutions/6602383/502-ipo-by-nalindalal2004-wjex/
