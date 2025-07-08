//1751. Maximum Number of Events That Can Be Attended II
use std::cmp::max;
impl Solution {
    pub fn max_value(mut events: Vec<Vec<i32>>, k: i32) -> i32 {
        events.sort_by_key(|e| e[0]);
        let n = events.len();
        let mut start_times: Vec<i32> = events.iter().map(|e| e[0]).collect();

        // Binary search to find next event index
        fn find_next_index(start_times: &[i32], end: i32) -> usize {
            let mut low = 0;
            let mut high = start_times.len();
            while low < high {
                let mid = (low + high) / 2;
                if start_times[mid] > end {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            low
        }

        let mut next_index = vec![n; n];
        for i in 0..n {
            next_index[i] = find_next_index(&start_times, events[i][1]);
        }

        let k = k as usize;
        let mut dp = vec![vec![0; k + 1]; n + 1];

        for i in (0..n).rev() {
            for j in 1..=k {
                let take = events[i][2] + dp[next_index[i]][j - 1];
                let skip = dp[i + 1][j];
                dp[i][j] = max(skip, take);
            }
        }

        dp[0][k]
    }
}
//sub: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/submissions/1690501039/?envType=daily-question&envId=2025-07-08
//sol: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/solutions/6934148/1751-maximum-number-of-events-that-can-b-xrep/
