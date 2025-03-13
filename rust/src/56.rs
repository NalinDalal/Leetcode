//56. Merge Intervals
impl Solution {
    pub fn merge(mut intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        if intervals.is_empty() {
            return Vec::new();
        }

        // Sort intervals based on the start time
        intervals.sort_by(|a, b| a[0].cmp(&b[0]));

        let mut merged: Vec<Vec<i32>> = Vec::new();

        for interval in intervals {
            if merged.is_empty() || merged.last().unwrap()[1] < interval[0] {
                // No overlap, push new interval
                merged.push(interval);
            } else {
                // Overlapping intervals, merge them
                let last = merged.last_mut().unwrap();
                last[1] = last[1].max(interval[1]);
            }
        }

        merged
    }
}

// Example Usage
fn main() {
    let intervals = vec![vec![1, 3], vec![2, 6], vec![8, 10], vec![15, 18]];
    let result = Solution::merge(intervals);
    println!("{:?}", result); // Output: [[1,6],[8,10],[15,18]]
}
//sub: https://leetcode.com/problems/merge-intervals/submissions/1572142751/
//sol: https://leetcode.com/problems/merge-intervals/solutions/6531398/56-merge-intervals-by-nalindalal2004-uam4/
