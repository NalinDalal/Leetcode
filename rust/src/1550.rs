//1550. Three Consecutive Odds
impl Solution {
    pub fn three_consecutive_odds(arr: Vec<i32>) -> bool {
        if arr.len() < 3 {
            return false; // early return to avoid out-of-bounds
        }

        for i in 0..arr.len() - 2 {
            if arr[i] % 2 != 0 && arr[i + 1] % 2 != 0 && arr[i + 2] % 2 != 0 {
                return true; // found 3 consecutive odds
            }
        }

        false
    }
}
//sub: https://leetcode.com/problems/three-consecutive-odds/submissions/1630819724/?envType=daily-question&envId=2025-05-11
