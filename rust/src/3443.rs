//3443. Maximum Manhattan Distance After K Changes
use std::cmp::{max, min};

impl Solution {
    pub fn max_distance(s: String, k: i32) -> i32 {
        let mut ans = 0;
        let (mut north, mut south, mut east, mut west) = (0, 0, 0, 0);
        for c in s.chars() {
            match c {
                'N' => north += 1,
                'S' => south += 1,
                'E' => east += 1,
                'W' => west += 1,
                _ => (),
            }
            let times1 = min(min(north, south), k); // modification times for N and S
            let times2 = min(min(east, west), k - times1); // modification times for E and W
            let current = Self::count(north, south, times1) + Self::count(east, west, times2);
            ans = max(ans, current);
        }
        ans
    }

    fn count(drt1: i32, drt2: i32, times: i32) -> i32 {
        (drt1 - drt2).abs() + times * 2
    } // Calculate modified Manhattan distance
}

//sub: https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/submissions/1670771916/?envType=daily-question&envId=2025-06-20

//sol: https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/solutions/6866400/3443-maximum-manhattan-distance-after-k-0p1xk/
