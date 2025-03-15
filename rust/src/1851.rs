//1851. Minimum Interval to Include Each Query

use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
    pub fn min_interval(intervals: Vec<Vec<i32>>, queries: Vec<i32>) -> Vec<i32> {
        let mut intervals = intervals;
        intervals.sort_by_key(|x| x[0]); // Sort intervals by start

        let mut queries: Vec<(i32, usize)> = queries
            .into_iter()
            .enumerate()
            .map(|(i, q)| (q, i)) // Swap the tuple order
            .collect();
        queries.sort(); // Sort queries by value

        let mut result = vec![-1; queries.len()];
        let mut min_heap = BinaryHeap::new(); // Min-Heap storing (size, end)
        let mut i = 0;

        for (query, index) in queries {
            // Add all valid intervals to heap
            while i < intervals.len() && intervals[i][0] <= query {
                let start = intervals[i][0];
                let end = intervals[i][1];
                min_heap.push(Reverse((end - start + 1, end))); // (size, end)
                i += 1;
            }

            // Remove intervals that have ended
            while let Some(Reverse((size, end))) = min_heap.peek() {
                if *end < query {
                    min_heap.pop();
                } else {
                    result[index] = *size;
                    break;
                }
            }
        }

        result
    }
}
//sub: https://leetcode.com/problems/minimum-interval-to-include-each-query/submissions/1574443628/
//sol: https://leetcode.com/problems/minimum-interval-to-include-each-query/solutions/6539110/1851-minimum-interval-to-include-each-qu-pfvn/
